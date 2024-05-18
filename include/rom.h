#ifndef __ROM_H
#define __ROM_H



class ROM{
private:
    const unsigned char *rom;

    long long pos;
public:
    ROM(const unsigned char *vrom){
        rom = vrom;
        pos = 0;
    }
    ~ROM(){pos= 0;}

    bool read(char* path,long long size);

    operator bool();
};

#endif