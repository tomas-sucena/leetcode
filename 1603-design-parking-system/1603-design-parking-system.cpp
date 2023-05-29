class ParkingSystem {
    int big;
    int medium;
    int small;
    
public:
    ParkingSystem(int big, int medium, int small) : big(big), medium(medium), small(small) {}
    
    bool addCar(int carType) {
        switch (carType) {
            case (1) : {
                if (!big) return false;
                --big;

                break;
            }
            case (2) : {
                if (!medium) return false;
                --medium;

                break;
            }
            case (3) : {
                if (!small) return false;
                --small;

                break;
            }
            default : return false;
        }

        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */