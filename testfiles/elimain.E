# 1 "elimain.cpp"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 318 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "elimain.cpp" 2


# 1 "./eliheader.h" 1





struct Person {
  int val;
};


class Room {
public:
    void add_person(Person person)
    {

    }

private:
    Person* people_in_room;
};
# 4 "elimain.cpp" 2

int myglobal=20;;

int main()
{
    Person* p = new Person();
    p->val = myglobal;

    return 0;
}
