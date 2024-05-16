#include "Mapper.h"
#include "CPUOpcodes.h"
#include "MapperNROM.h"

namespace sn
{
    NameTableMirroring Mapper::getNameTableMirroring()
    {
        return static_cast<NameTableMirroring>((Byte)1);
    }

    std::unique_ptr<Mapper> Mapper::createMapper(Mapper::Type mapper_t, sn::Cartridge& cart, std::function<void()> interrupt_cb, std::function<void(void)> mirroring_cb)
    {
        std::unique_ptr<Mapper> ret(nullptr);
        ret.reset(new MapperNROM(cart));
        return ret;
    }
}
