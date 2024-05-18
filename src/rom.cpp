 #include "rom.h"



 bool ROM::read(char* path,long long size) {
     for (int i = 0; i < size; ++i) {
         path[i] = rom[pos];
         ++pos;

     }
     return true;
 }

 ROM::operator bool() {
     return rom != nullptr;
 }
