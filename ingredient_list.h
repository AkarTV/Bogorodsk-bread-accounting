#ifndef INGREDIENTS_LIST_H
#define INGREDIENTS_LIST_H
#include "ingredient.h"
#include "QList"

class Flour_VS : public ingredient{
public:
    static Flour_VS& make()
    {
        static Flour_VS flour_vs;
        return flour_vs;
    }
private:
    Flour_VS() : ingredient(1) {}
    Flour_VS(const Flour_VS&);
    Flour_VS& operator=(const Flour_VS&);
};
static Flour_VS& flour_vs = Flour_VS::make();


class Flour_1S : public ingredient{
public:
    static Flour_1S& make()
    {
        static Flour_1S flour_1s;
        return flour_1s;
    }
private:
    Flour_1S() : ingredient(2) {}
    Flour_1S(const Flour_1S&);
    Flour_1S& operator=(const Flour_1S&);
};
static Flour_1S& flour_1s = Flour_1S::make();


class Flour_Rj : public ingredient{
public:
    static Flour_Rj& make()
    {
        static Flour_Rj flour_rj;
        return flour_rj;
    }
private:
    Flour_Rj() : ingredient(3) {}
    Flour_Rj(const Flour_Rj&);
    Flour_Rj& operator=(const Flour_Rj&);
};
static Flour_Rj& flour_rj = Flour_Rj::make();


class Sault : public ingredient{
public:
    static Sault& make()
    {
        static Sault sault;
        return sault;
    }
private:
    Sault() : ingredient(4) {}
    Sault(const Sault&);
    Sault& operator=(const Sault&);
};
static Sault& sault = Sault::make();


class Sugar : public ingredient{
public:
    static Sugar& make()
    {
        static Sugar sugar;
        return sugar;
    }
private:
    Sugar() : ingredient(5) {}
    Sugar(const Sugar&);
    Sugar& operator=(const Sugar&);
};
static Sugar& sugar = Sugar::make();


class Oil : public ingredient{
public:
    static Oil& make()
    {
        static Oil oil;
        return oil;
    }
private:
    Oil() : ingredient(6) {}
    Oil(const Oil&);
    Oil& operator=(const Oil&);
};
static Oil& oil = Oil::make();


class Droji : public ingredient{
public:
    static Droji& make()
    {
        static Droji droji;
        return droji;
    }
private:
    Droji() : ingredient(7) {}
    Droji(const Droji&);
    Droji& operator=(const Droji&);
};
static Droji& droji = Droji::make();


class Solod : public ingredient{
public:
    static Solod& make()
    {
        static Solod solod;
        return solod;
    }
private:
    Solod() : ingredient(8) {}
    Solod(const Solod&);
    Solod& operator=(const Solod&);
};
static Solod& solod = Solod::make();


class Margarin : public ingredient{
public:
    static Margarin& make()
    {
        static Margarin margarin;
        return margarin;
    }
private:
    Margarin() : ingredient(9) {}
    Margarin(const Margarin&);
    Margarin& operator=(const Margarin&);
};
static Margarin& margarin = Margarin::make();


class Tvorog : public ingredient{
public:
    static Tvorog& make()
    {
        static Tvorog tvorog;
        return tvorog;
    }
private:
    Tvorog() : ingredient(10) {}
    Tvorog(const Tvorog&);
    Tvorog& operator=(const Tvorog&);
};
static Tvorog& tvorog = Tvorog::make();


class Egg : public ingredient{
public:
    static Egg& make()
    {
        static Egg egg;
        return egg;
    }
private:
    Egg() : ingredient(11) {}
    Egg(const Egg&);
    Egg& operator=(const Egg&);
};
static Egg& egg = Egg::make();


class Sausage : public ingredient{
public:
    static Sausage& make()
    {
        static Sausage sausage;
        return sausage;
    }
private:
    Sausage() : ingredient(12) {}
    Sausage(const Sausage&);
    Sausage& operator=(const Sausage&);
};
static Sausage& sausage = Sausage::make();


class Jam : public ingredient{
public:
    static Jam& make()
    {
        static Jam jam;
        return jam;
    }
private:
    Jam() : ingredient(13) {}
    Jam(const Jam&);
    Jam& operator=(const Jam&);
};
static Jam& jam = Jam::make();


class Otrubi : public ingredient{
public:
    static Otrubi& make()
    {
        static Otrubi otrubi;
        return otrubi;
    }
private:
    Otrubi() : ingredient(14) {}
    Otrubi(const Otrubi&);
    Otrubi& operator=(const Otrubi&);
};
static Otrubi& otrubi = Otrubi::make();


class Kunjut : public ingredient{
public:
    static Kunjut& make()
    {
        static Kunjut kunjut;
        return kunjut;
    }
private:
    Kunjut() : ingredient(15) {}
    Kunjut(const Kunjut&);
    Kunjut& operator=(const Kunjut&);
};
static Kunjut& kunjut = Kunjut::make();


class Mayonez : public ingredient{
public:
    static Mayonez& make()
    {
        static Mayonez mayonez;
        return mayonez;
    }
private:
    Mayonez() : ingredient(16) {}
    Mayonez(const Mayonez&);
    Mayonez& operator=(const Mayonez&);
};
static Mayonez& mayonez = Mayonez::make();


class Chesnok : public ingredient{
public:
    static Chesnok& make()
    {
        static Chesnok chesnok;
        return chesnok;
    }
private:
    Chesnok() : ingredient(17) {}
    Chesnok(const Chesnok&);
    Chesnok& operator=(const Chesnok&);
};
static Chesnok& chesnok = Chesnok::make();


class Luk : public ingredient{
public:
    static Luk& make()
    {
        static Luk luk;
        return luk;
    }
private:
    Luk() : ingredient(18) {}
    Luk(const Luk&);
    Luk& operator=(const Luk&);
};
static Luk& luk = Luk::make();


class Green_Luk : public ingredient{
public:
    static Green_Luk& make()
    {
        static Green_Luk green_luk;
        return green_luk;
    }
private:
    Green_Luk() : ingredient(19) {}
    Green_Luk(const Green_Luk&);
    Green_Luk& operator=(const Green_Luk&);
};
static Green_Luk& green_luk = Green_Luk::make();


class Cheese : public ingredient{
public:
    static Cheese& make()
    {
        static Cheese cheese;
        return cheese;
    }
private:
    Cheese() : ingredient(20) {}
    Cheese(const Cheese&);
    Cheese& operator=(const Cheese&);
};
static Cheese& cheese = Cheese::make();


class Cabbage : public ingredient{
public:
    static Cabbage& make()
    {
        static Cabbage cabbage;
        return cabbage;
    }
private:
    Cabbage() : ingredient(21) {}
    Cabbage(const Cabbage&);
    Cabbage& operator=(const Cabbage&);
};
static Cabbage& cabbage = Cabbage::make();


class Farsh : public ingredient{
public:
    static Farsh& make()
    {
        static Farsh farsh;
        return farsh;
    }
private:
    Farsh() : ingredient(22) {}
    Farsh(const Farsh&);
    Farsh& operator=(const Farsh&);
};
static Farsh& farsh = Farsh::make();

static QList<ingredient*> ingredient_list = {
    &flour_vs, &flour_1s, &flour_rj, &sault, &sugar, &droji, &oil, &solod, &margarin,
    &tvorog, &egg, &sausage, &jam, &otrubi, &kunjut, &mayonez, &chesnok, &luk, &green_luk, &cheese, &cabbage, &farsh
};




#endif // INGREDIENTS_LIST_H
