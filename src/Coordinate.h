//A simple coordinate point
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

