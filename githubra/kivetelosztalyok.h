#ifndef KIVETELOSZTALYOK_H_INCLUDED
#define KIVETELOSZTALYOK_H_INCLUDED

class Exception {
public:
    virtual std::string hiba_oka() const = 0;
};

class NotNumber_kiadasiev :public Exception {
public:
    std::string hiba_oka() const {
        return "A kiadasiev nem egesz szam!";
    }
};

class NotNumber_evfolyam :public Exception {
public:
    std::string hiba_oka() const {
        return "Az evfolyam nem egesz szam!";
    }
};

class OutOfRange_kiadasiev :public Exception {
public:
    std::string hiba_oka() const {
        return "Osregi vagy tul vadonatuj a konyv!";
    }
};

class OutOfRange_evfolyam :public Exception {
public:
    std::string hiba_oka() const {
        return "Nem letezo evfolyamot adott meg!";;
    }
};

class OutOfRange_index:public Exception {
public:
    std::string hiba_oka() const {
        return "Nincs benne az aznosito!";;
    }
};

class Empty_lista :public Exception {
public:
    std::string hiba_oka() const {
        return "Ures a lista!";
    }
};

class Incorrect_input :public Exception {
public:
    std::string hiba_oka() const {
        return "Helytelen adatbevitel!";
    }
};









#endif