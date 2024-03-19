#ifndef CPU_EMULATOR_SERIALIZATION_H
#define CPU_EMULATOR_SERIALIZATION_H

#include <vector>
#include <fstream>

namespace cpu_emulator::serialization {
    class Serializable {
        std::vector<bool> code;

        void Serialize(std::ostream& os);
        void Deserialize(std::istream& is);
    };

    class Deserializer{

    };
}



#endif //CPU_EMULATOR_SERIALIZATION_H
