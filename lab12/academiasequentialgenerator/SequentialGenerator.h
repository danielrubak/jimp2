#ifndef JIMP2_SEQUENTIALGENERATOR_H
#define JIMP2_SEQUENTIALGENERATOR_H

template <class C, typename T>
class SequentialIdGenerator {
    public:
        SequentialIdGenerator() { mCounter = T(0); }
        SequentialIdGenerator (T initValue) { mCounter = initValue; }
        C NextValue() {
            C newObject(mCounter);
            ++mCounter;
            return newObject;
        }
    private:
        T mCounter;
};

#endif //JIMP2_SEQUENTIALGENERATOR_H
