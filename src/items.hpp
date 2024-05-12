
class items{
    
public:
    items();
    void itemsX();
    void itemsY();
};

class fruit : public items{
    int fruitX, fruitY;
public:
    fruit();
    void setfruit();
    void isgetfruit();
    void drawfruit(const int , const int);

};

class poison : public items{
    int poisonX, poisonY;
public:
    poison();
    void setpoison();
    void isgetpoison();
    void drawpoison(const int, const int);
};