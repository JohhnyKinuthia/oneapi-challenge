//A simple coordinate point
#include <ostream>
struct Coordinate
{
        public:
                Coordinate(double latitude, double longitude): lat(latitude), longit(longitude){}
                Coordinate(): lat(0), longit(0){}
                double latitude() const {
                        return lat;
                }
                double longitude() const {
                        return longit;
                }

        private:
                double lat;
                double longit;
};

std::ostream& operator<<(std::ostream& os, const Coordinate& obj)
{
   // write obj to stream
   return os << obj.latitude() << ", " << obj.longitude();
}

