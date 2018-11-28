#ifndef _XUNIT_H_
#define _XUNIT_H_

#include <ratio>

namespace unit{
    using int64 = long long;
    
    template <class TypeTag,class Ratio>
    class Unit{
    public:
        using ratio = Ratio;
        using type_tag = TypeTag;
    
        Unit(int64 count):m_count(count){}
        ~Unit() = default;
        
        int64 count()const noexcept{ return m_count; }
        operator float()const noexcept{
            return static_cast<float>(m_count) * static_cast<float>(Ratio::num) / static_cast<float>(Ratio::den);
        }
        operator double()const noexcept{
            return static_cast<double>(m_count) * static_cast<double>(Ratio::num) / static_cast<double>(Ratio::den);
        }
    protected:
    private:
        int64 m_count;
    };
    
    class BinaryUnit{};
    using Byte = Unit<BinaryUnit,std::ratio<1,1>>;
    using KB = Unit<BinaryUnit,std::ratio<1024,1>>;
    using MB = Unit<BinaryUnit,std::ratio<1048576,1>>;
    using GB = Unit<BinaryUnit,std::ratio<1073741824,1>>;
    using TB = Unit<BinaryUnit,std::ratio<1099511627776,1>>;
    using bit = Unit<BinaryUnit,std::ratio<1,8>>;
    using Kb = Unit<BinaryUnit,std::ratio<1024,8>>;
    using Mb = Unit<BinaryUnit,std::ratio<1048576,8>>;
    using Gb = Unit<BinaryUnit,std::ratio<1073741824,8>>;
    
    class TimeUnit{};
    using nanosecond = Unit<TimeUnit,std::ratio<1,1000000000>>;
    using microsecond = Unit<TimeUnit,std::ratio<1,1000000>>;
    using millisecond = Unit<TimeUnit,std::ratio<1,1000>>;
    using second = Unit<TimeUnit,std::ratio<1,1>>;
    using minute = Unit<TimeUnit,std::ratio<60,1>>;
    using hour = Unit<TimeUnit,std::ratio<3600,1>>;
    using day = Unit<TimeUnit,std::ratio<86400,1>>;
    using week = Unit<TimeUnit,std::ratio<604800,1>>;
    
    class LengthUnit{};
    using nanometer = Unit<LengthUnit,std::ratio<1,1000000000>>;
    using micrometer = Unit<LengthUnit,std::ratio<1,1000000>>;
    using millimeter = Unit<LengthUnit,std::ratio<1,1000>>;
    using centimeter = Unit<LengthUnit,std::ratio<1,100>>;
    using decimeter = Unit<LengthUnit,std::ratio<1,10>>;
    using meter = Unit<LengthUnit,std::ratio<1,1>>;
    using kilometer = Unit<LengthUnit,std::ratio<1000,1>>;
    
    class MassUnit{};
    using microgram = Unit<MassUnit,std::ratio<1,1000000>>;
    using milligram = Unit<MassUnit,std::ratio<1,1000>>;
    using carat = Unit<MassUnit,std::ratio<1,5>>;
    using gram = Unit<MassUnit,std::ratio<1,1>>;
    using kilogram = Unit<MassUnit,std::ratio<1000,1>>;
    using ton = Unit<MassUnit,std::ratio<1000000,1>>;
    
    class AngleUnit{};
    using degree = Unit<AngleUnit,std::ratio<1,1>>;
}

template <class Dst,class Src>
constexpr Dst unit_cast(const Src &src){
    static_assert(std::is_same<typename Dst::type_tag,typename Src::type_tag>::value,"Cannot convert unit!");
    return Dst(src.count() * Src::ratio::num / Src::ratio::den * Dst::ratio::den / Dst::ratio::num);
}

#endif
