#include "Cartridge.h"
#include "Log.h"
#include "Mapper.h"

#include <fstream>
#include <string>

#include "rom.h"
#include "smb.h"
namespace sn
{
    Cartridge::Cartridge() : m_nameTableMirroring(0),
                             m_mapperNumber(0),
                             m_extendedRAM(false)
    {
    }
    const std::vector<Byte> &Cartridge::getROM()
    {
        return m_PRG_ROM;
    }

    const std::vector<Byte> &Cartridge::getVROM()
    {
        return m_CHR_ROM;
    }


    bool Cartridge::hasExtendedRAM()
    {
        return false;
    }

    bool Cartridge::loadFromFile(std::string path)
    {
//        std::ifstream romFile(path, std::ios_base::binary | std::ios_base::in);
        ROM romFile(smb_nes);
        if (!romFile)//若romFile为0指针则说明没有打开
        {
            LOG(Error) << "Could not open ROM file from path: " << path << std::endl;
            return false;
        }

        std::vector<Byte> header;

        // Header
        header.resize(0x10);
        romFile.read(reinterpret_cast<char *>(&header[0]), 0x10);


        Byte banks = header[4];
        LOG(Info) << "16KB PRG-ROM Banks: " << +banks << std::endl;

        Byte vbanks = header[5];
        LOG(Info) << "8KB CHR-ROM Banks: " << +vbanks << std::endl;

        m_mapperNumber = ((header[6] >> 4) & 0xf) | (header[7] & 0xf0);
        LOG(Info) << "Mapper #: " << +m_mapperNumber << std::endl;

        m_extendedRAM = header[6] & 0x2;
        LOG(Info) << "Extended (CPU) RAM: " << std::boolalpha << m_extendedRAM << std::endl;


        // PRG-ROM 16KB banks
        m_PRG_ROM.resize(0x4000 * banks);
        if (!romFile.read(reinterpret_cast<char *>(&m_PRG_ROM[0]), 0x4000 * banks))
        {
            LOG(Error) << "Reading PRG-ROM from image file failed." << std::endl;
            return false;
        }

        // CHR-ROM 8KB banks
        if (vbanks)
        {
            m_CHR_ROM.resize(0x2000 * vbanks);
            if (!romFile.read(reinterpret_cast<char *>(&m_CHR_ROM[0]), 0x2000 * vbanks))
            {
                LOG(Error) << "Reading CHR-ROM from image file failed." << std::endl;
                return false;
            }
        }
        else
            LOG(Info) << "Cartridge with CHR-RAM." << std::endl;
        return true;
    }
}
