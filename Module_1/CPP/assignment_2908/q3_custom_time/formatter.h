#ifndef FORMATTER_H
#define FORMATTER_H

// write all members and function as static so that no object required to call the class methods
class Formatter{
    public:
            static int formateHours(int totalMinutes){
                return totalMinutes / 60;
            }
            static int formateMinutes(int totalMinutes){
                return totalMinutes % 60;
            }
};

#endif