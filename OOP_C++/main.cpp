#include <iostream>
#include <string>
#include <cctype>
#include <stdexcept>
#include <fstream>
#include <cstdlib>
using namespace std;



// Класс элемента автомобиля
class Element
{
protected:
   string name;
   unsigned int price;
    
public:
    Element(unsigned int price,string name)
    {
        this->name = name;
        this->price = price;
    }
    
     void setPrice(unsigned int price)
    {
        this->price = price;
    }
    
    unsigned int getPrice()
    {
        return price;
    }
      
    void setName(string name)
    {
        this->name = name;
    }
    
    string getName()
    {
        return name;
    }
       
    
    ~Element() {}
};



// Классы внешних элементов  автомобиля

// Класс колеса
class Wheel: public Element
{
    public:
        Wheel(unsigned int price):Element(price,"wheel") {}
};

// Класс Двери
class Door: public Element
{
    public:
        Door (unsigned int price):Element(price,"door") {}
    
};

// Класс Багажника
class Trunk: public Element
{
    public:
        Trunk(unsigned int price):Element(price,"trunk") {}
};

// Класс Капота
class Hood: public Element
{
    public:
        Hood(unsigned int price) : Element(price,"hood") {}
};



// Класс фар автомобиля
class Headlights: public Element
{
    public:
    Headlights(unsigned int price) : Element(price,"headlights") {}
};





// Классы внутренних элементов машины

// Класс аккамулятора автомобиля
class Battery: public Element
{
    public:
    Battery(unsigned int price) : Element(price,"battery") {}
};

// Класс трансмиссии автомобиля
class Transmission: public Element
{
    public:
    Transmission(unsigned int price) : Element(price,"transmission") {}
};

//Класс турбонаддува автомобиля
class Turbocharging: public Element
{
    public:
    Turbocharging(unsigned int price) : Element(price,"turbocharging") {}

};

class emergency_lights: public Element
{
    public:
    emergency_lights(unsigned int price) : Element(price,"emergency_lights") {}
};

// Класс тормозного клапана
class Brake_Valve: public Element
{
    public:
    Brake_Valve(unsigned int price) : Element(price,"brake_valve") {}
};


// Общую стоимость элемента машины
class ElementFolder
{
    string name;
    unsigned int count;
    Element * element;
    
public:
    ElementFolder(string name,unsigned int count,unsigned int price)
    {
        this->count = count;
        if(name == "door")
            element  = new Door(price);
        else if (name == "wheel")
            element = new Wheel(price);
        else if (name == "trunk")
            element = new Trunk(price);
        else if (name == "hood")
            element = new Hood(price);
//        else if (name == "disk")
//            element = new Disk(price);
        else if (name == "headlights")
            element = new Headlights(price);
        else if (name == "battery")
            element = new Battery(price);
        else if (name == "transmission")
            element = new Transmission(price);
        else if (name == "turbocharging")
            element = new Turbocharging(price);
        else if (name == "brake_valve")
            element = new Brake_Valve(price);
//        else if ()
//        else throw new invalid_argument("incorrect name");
    }
    
    ~ElementFolder()
    {
        delete element;
    }
    
    unsigned int allCost()
    {
        return element->getPrice() * count;
    }
    
    
    
};


// Класс Автомобиля
class Car
{
    string name;
    ElementFolder wheels;
    ElementFolder doors;
    ElementFolder trunks;
    ElementFolder hood;
    //ElementFolder disk;
    ElementFolder headlights;
    ElementFolder batterys;
    ElementFolder transmissions;
    ElementFolder turbochargings;
    ElementFolder brake_valves;
public:
    Car (string name,
         unsigned int wheels_count,
         unsigned int doors_count,
         unsigned int trunks_count,
         unsigned int hood_count,
         //unsigned int disk_count,
         unsigned int headlights_count,
         unsigned int battery_count,
         unsigned int transmission_count,
         unsigned int turbocharging_count,
         unsigned int brake_valves_count,
         unsigned int wheels_price,
         unsigned int doors_price,
         unsigned int trunks_price,
         unsigned int hood_price,
         //unsigned int disk_price,
         unsigned int headlights_price,
         unsigned int battery_price,
         unsigned int transmission_price,
         unsigned int turbocharging_price,
         unsigned int brake_valves_price
         ) : wheels("wheel",wheels_count, wheels_price),
             doors("door",doors_count,doors_price),
             trunks("trunk",trunks_count, trunks_price),
             hood("hood",hood_count,hood_price),
             //disk("disk",disk_count,disk_price),
             headlights("headlights",headlights_count,headlights_price),
             batterys("battery",battery_count,battery_price),
             transmissions("transmission",transmission_count,transmission_price),
             turbochargings("turbocharging",turbocharging_count,turbocharging_price),
             brake_valves("brake_valve",brake_valves_count,brake_valves_price)
    {
        this->name = name;
    }
    unsigned int carPrice()
    {
        return wheels.allCost()+doors.allCost()+trunks.allCost()+hood.allCost()+headlights.allCost()+batterys.allCost()+transmissions.allCost()+turbochargings.allCost()+brake_valves.allCost()
        ;
    }
};






int main()
{
    int price_wheel;
    int numeric_wheel;
    int price_door;
    int numeric_door;
    int numeric_trunk;
    int price_trunk;
    int price_hood;
    int numeric_hood;
//  int price_disk;
//  int numeric_disk;
    int price_headlights;
    int numeric_headlights;
    int price_battery;
    int numeric_battery;
    int price_transmission;
    int numeric_transmission;
    int price_turbocharging;
    int numeric_turbocharging;
    int price_brake_valve;
    int numeric_brake_valve;
    cout << "Подсчёт общей стоимости и отдельных компонентов автомобиля." << endl;
    cout << endl;
        
    
        while ( true )
        {
               cout << "Введите стоимость колеса для автомобиля: ";
               cin >> price_wheel;
               if ( cin.peek() == '\n' )
               { //если ввели целое число, значит в буфере осталось  только /n
                   cin.get(); //очистить от /n
                   break; //выйти из цикла
               } else
               { //если в буфере осталось не только /n
                   cout << "Ожидается целое число! Повторите ввод!" << endl;
                   cin.clear(); //сброс всех ошибок потока
                   while ( cin.get() != '\n' ) { //извлечь из буфера все символы включая /n
                   }
               }
           }
        
        
        if (price_wheel <= 0)
        {
            cout << "Введенно отрицuательное число" << endl;
            return 0;
        }
    
    
        while ( true )
        {
               cout << "Введите количество колёс на автомобиле(4-10): ";
               cin >> numeric_wheel;
               if ( cin.peek() == '\n' )
               { //если ввели целое число, значит в буфере осталось  только /n
                   cin.get(); //очистить от /n
                   break; //выйти из цикла
               } else
               { //если в буфере осталось не только /n
                   cout << "Ожидается целое число! Повторите ввод!" << endl;
                   cin.clear(); //сброс всех ошибок потока
                   while ( cin.get() != '\n' ){ //извлечь из буфера все символы включая /n
                   }
               }
           }
    
      
        
        if (numeric_wheel < 4 || numeric_wheel > 10)
        {
            cout << "Введенно некорректное число колёс" << endl;
            return 0;
        }
    
        cout << endl;
    
    
        
        
       while ( true )
       {
              cout<< "Введите стоимость двери: ";
              cin >> price_door;
              if ( cin.peek() == '\n' )
              { //если ввели целое число, значит в буфере осталось  только /n
                  cin.get(); //очистить от /n
                  break; //выйти из цикла
              } else
              { //если в буфере осталось не только /n
                  cout << "Ожидается целое число! Повторите ввод!" << endl;
                  cin.clear(); //сброс всех ошибок потока
                  while ( cin.get() != '\n' )
                  { //извлечь из буфера все символы включая /n
                  }
              }
          }

        if (price_door <= 0)
        {
            cout << "Введенно отрицuательное число" << endl;
            return 0;
        }
        
    
        while (true)
        {
               cout << "Введите количество дверей(2-8): ";
               cin >> numeric_door;
               if ( cin.peek() == '\n' )
               { //если ввели целое число, значит в буфере осталось  только /n
                   cin.get(); //очистить от /n
                   break; //выйти из цикла
               } else
               { //если в буфере осталось не только /n
                   cout << "Ожидается целое число! Повторите ввод!" << endl;
                   cin.clear(); //сброс всех ошибок потока
                   while ( cin.get() != '\n' ) { //извлечь из буфера все символы включая /n
                   }
               }
           }
    
        if (numeric_door < 2 || numeric_door > 8)
        {
            cout << "Введенно некорректное число дверей" << endl;
            return 0;
        }
    
        cout << endl;
    
    
    
    
        while (true)
           {
                  cout << "Введите стоимость багажника: ";
                  cin >> price_trunk;
                  if ( cin.peek() == '\n' )
                  { //если ввели целое число, значит в буфере осталось  только /n
                      cin.get(); //очистить от /n
                      break; //выйти из цикла
                  } else
                  { //если в буфере осталось не только /n
                      cout << "Ожидается целое число! Повторите ввод!" << endl;
                      cin.clear(); //сброс всех ошибок потока
                      while ( cin.get() != '\n' ) { //извлечь из буфера все символы включая /n
                      }
                  }
              }
            
        
       
        if (price_trunk <= 0)
        {
            cout << "Введенно отрицuательное число" << endl;
            return 0;
        }
    
    
    while (true)
    {
           cout << "Введите количество багажников(1-2): ";
           cin >> numeric_trunk;
           if ( cin.peek() == '\n' )
           { //если ввели целое число, значит в буфере осталось  только /n
               cin.get(); //очистить от /n
               break; //выйти из цикла
           } else
           { //если в буфере осталось не только /n
               cout << "Ожидается целое число! Повторите ввод!" << endl;
               cin.clear(); //сброс всех ошибок потока
               while ( cin.get() != '\n' ) { //извлечь из буфера все символы включая /n
               }
           }
       }
    
        
        if (numeric_trunk <= 0 || numeric_trunk > 2)
        {
            cout << "Введенно некорректное число багажников" << endl;
            return 0;
        }
    
        cout << endl;
        
    
        while (true)
       {
              cout << "Введите стоимость капота: ";
              cin >> price_hood;
              if ( cin.peek() == '\n' )
              { //если ввели целое число, значит в буфере осталось  только /n
                  cin.get(); //очистить от /n
                  break; //выйти из цикла
              } else
              { //если в буфере осталось не только /n
                  cout << "Ожидается целое число! Повторите ввод!" << endl;
                  cin.clear(); //сброс всех ошибок потока
                  while ( cin.get() != '\n' ) { //извлечь из буфера все символы включая /n
                  }
              }
          }
    
       
      
        if (price_hood <= 0)
        {
            cout << "Введенно отрицuательное число" << endl;
            return 0;
        }
    
    
    
        while (true)
       {
              cout << "Введите количество капотов(1-2): ";
              cin >> numeric_hood;
              if ( cin.peek() == '\n' )
              { //если ввели целое число, значит в буфере осталось  только /n
                  cin.get(); //очистить от /n
                  break; //выйти из цикла
              } else
              { //если в буфере осталось не только /n
                  cout << "Ожидается целое число! Повторите ввод!" << endl;
                  cin.clear(); //сброс всех ошибок потока
                  while ( cin.get() != '\n' ) { //извлечь из буфера все символы включая /n
                  }
              }
          }
    
    
        if (numeric_hood <= 0 || numeric_hood > 2)
        {
            cout << "Введенн о некорректное число капотов" << endl;
            return 0;
        }
    
    cout << endl;
    
        while (true)
              {
                     cout << "Введите стоимость фары: ";
                     cin >> price_headlights;
                     if ( cin.peek() == '\n' )
                     { //если ввели целое число, значит в буфере осталось  только /n
                         cin.get(); //очистить от /n
                         break; //выйти из цикла
                     } else
                     { //если в буфере осталось не только /n
                         cout << "Ожидается целое число! Повторите ввод!" << endl;
                         cin.clear(); //сброс всех ошибок потока
                         while ( cin.get() != '\n' ) { //извлечь из буфера все символы включая /n
                         }
                     }
                 }
            
        
    
        if (price_headlights <= 0)
        {
            cout << "Введенно отрицuательное число" << endl;
            return 0;
        }
        
        while (true)
          {
                 cout << "Введите количество фар(1-5): ";
                 cin >> numeric_headlights;
                 if ( cin.peek() == '\n' )
                 { //если ввели целое число, значит в буфере осталось  только /n
                     cin.get(); //очистить от /n
                     break; //выйти из цикла
                 } else
                 { //если в буфере осталось не только /n
                     cout << "Ожидается целое число! Повторите ввод!" << endl;
                     cin.clear(); //сброс всех ошибок потока
                     while ( cin.get() != '\n' ) { //извлечь из буфера все символы включая /n
                     }
                 }
             }
    
    
        if (numeric_headlights <= 0 || numeric_headlights > 5)
        {
        cout << "Введенно некорректное число фар" << endl;
        return 0;
        }
        
       
    
        cout << endl;
        
    
            while (true)
             {
                    cout << "Введите стоимость батареи: ";
                    cin >> price_battery;
                    if ( cin.peek() == '\n' )
                    { //если ввели целое число, значит в буфере осталось  только /n
                        cin.get(); //очистить от /n
                        break; //выйти из цикла
                    } else
                    { //если в буфере осталось не только /n
                        cout << "Ожидается целое число! Повторите ввод!" << endl;
                        cin.clear(); //сброс всех ошибок потока
                        while ( cin.get() != '\n' ) { //извлечь из буфера все символы включая /n
                        }
                    }
                }
    
       
            if (price_battery <= 0)
              {
                  cout << "Введенно отрицuательное число" << endl;
                  return 0;
              }
    
    
        
            while (true)
             {
                    cout << "Введите количество батарей(1-2): ";
                     cin >> numeric_battery;
                    if ( cin.peek() == '\n' )
                    { //если ввели целое число, значит в буфере осталось  только /n
                        cin.get(); //очистить от /n
                        break; //выйти из цикла
                    } else
                    { //если в буфере осталось не только /n
                        cout << "Ожидается целое число! Повторите ввод!" << endl;
                        cin.clear(); //сброс всех ошибок потока
                        while ( cin.get() != '\n' ) { //извлечь из буфера все символы включая /n
                        }
                    }
                }
    
       
        if (numeric_battery <= 0 || numeric_battery > 2)
        {
            cout << "Введенно некорректное число батарей" << endl;
            return 0;
        }

        cout << endl;
    
    
    
        while (true)
    {
           cout << "Введите стоимость трансмиссии: ";
           cin >> price_transmission;
           if ( cin.peek() == '\n' )
           { //если ввели целое число, значит в буфере осталось  только /n
               cin.get(); //очистить от /n
               break; //выйти из цикла
           } else
           { //если в буфере осталось не только /n
               cout << "Ожидается целое число! Повторите ввод!" << endl;
               cin.clear(); //сброс всех ошибок потока
               while ( cin.get() != '\n' ) { //извлечь из буфера все символы включая /n
               }
           }
       }
        
    
        
        if (price_transmission <= 0)
        {
            cout << "Введенно отрицuательное число" << endl;
            return 0;
        }
    
        while (true)
        {
               cout << "Введите количество трансмиссий(1-2): ";
               cin >> numeric_transmission;
               if ( cin.peek() == '\n' )
               { //если ввели целое число, значит в буфере осталось  только /n
                   cin.get(); //очистить от /n
                   break; //выйти из цикла
               } else
               { //если в буфере осталось не только /n
                   cout << "Ожидается целое число! Повторите ввод!" << endl;
                   cin.clear(); //сброс всех ошибок потока
                   while ( cin.get() != '\n' ) { //извлечь из буфера все символы включая /n
                   }
               }
           }
            
        
        if (numeric_transmission <= 0 || numeric_transmission > 2)
        {
            cout << "Введенно некорректное число двигателей" << endl;
            return 0;
        }
    
        cout << endl;
    
    
            while (true)
               {
                    cout << "Введите стоимость турбонаддува: ";
                     cin >> price_turbocharging;
                      if ( cin.peek() == '\n' )
                      { //если ввели целое число, значит в буфере осталось  только /n
                          cin.get(); //очистить от /n
                          break; //выйти из цикла
                      } else
                      { //если в буфере осталось не только /n
                          cout << "Ожидается целое число! Повторите ввод!" << endl;
                          cin.clear(); //сброс всех ошибок потока
                          while ( cin.get() != '\n' ) { //извлечь из буфера все символы включая /n
                          }
                      }
                  }
  
   
        if (price_turbocharging <= 0)
        {
            cout << "Введенно отрицuательное число" << endl;
            return 0;
        }
    
        while (true)
        {
          cout << "Введите количество турбонаддувов(1-2): ";
          cin >> numeric_turbocharging;
           if ( cin.peek() == '\n' )
           { //если ввели целое число, значит в буфере осталось  только /n
               cin.get(); //очистить от /n
               break; //выйти из цикла
           } else
           { //если в буфере осталось не только /n
               cout << "Ожидается целое число! Повторите ввод!" << endl;
               cin.clear(); //сброс всех ошибок потока
               while ( cin.get() != '\n' ) { //извлечь из буфера все символы включая /n
               }
           }
       }

        if (numeric_turbocharging <= 0 || numeric_turbocharging > 2)
        {
            cout << "Введенно некорректное число турбонаддувов" << endl;
            return 0;
        }

        cout << endl;
    
    
        while (true)
     {
        cout << "Введите стоимость тормозного клапана: ";
        cin >> price_brake_valve;
        if ( cin.peek() == '\n' )
        { //если ввели целое число, значит в буфере осталось  только /n
            cin.get(); //очистить от /n
            break; //выйти из цикла
        } else
        { //если в буфере осталось не только /n
            cout << "Ожидается целое число! Повторите ввод!" << endl;
            cin.clear(); //сброс всех ошибок потока
            while ( cin.get() != '\n' ) { //извлечь из буфера все символы включая /n
            }
        }
    }

       
        
        if (price_brake_valve <= 0)
        {
            cout << "Введенно отрицuательное число" << endl;
            return 0;
        }
    
    
        while (true)
     {
        cout << "Введите количество тормозных клапанов(1-2): ";
        cin >> numeric_brake_valve;
        if ( cin.peek() == '\n' )
        { //если ввели целое число, значит в буфере осталось  только /n
            cin.get(); //очистить от /n
            break; //выйти из цикла
        } else
        { //если в буфере осталось не только /n
            cout << "Ожидается целое число! Повторите ввод!" << endl;
            cin.clear(); //сброс всех ошибок потока
            while ( cin.get() != '\n' ) { //извлечь из буфера все символы включая /n
            }
        }
    }

        
    
        if (numeric_brake_valve <= 0 || numeric_brake_valve > 2)
        {
            cout << "Введенно некорректное число тормозных клапанов" << endl;
            return 0;
        }
    cout << endl;
    

    

        cout << "Стоимость отдельных компонентов машины:" << endl;
        cout << endl;
        cout << "Стоимость колёс автомобиля: " << price_wheel*numeric_wheel << endl;
        cout << "Стоимость дверей автомобиля: " << price_door*numeric_door << endl;
     cout << "Стоимость багажника автомобиля: " << price_trunk*numeric_trunk << endl;
        cout << "Стоимость капота автомобиля: " << price_hood*numeric_hood << endl;
        //cout << "Стоимость дисков автомобиля:" << price_disk*numeric_disk << endl;
          cout << "Стоимость фары автомобиля: " << price_headlights*numeric_headlights << endl;
       cout << "Стоимость батареи автомобиля: " << price_battery*numeric_battery << endl;
    cout << "Стоимость трансмисси автомобиля: " << price_transmission*numeric_transmission << endl;
   cout << "Стоимость турбонадува автомобиля: " << price_turbocharging*numeric_turbocharging << endl;
    
    
    
    
    
        
        Car car("usa",
                numeric_wheel,
                numeric_door,
                numeric_trunk,
                numeric_hood,
                numeric_headlights,
                numeric_battery,
                numeric_transmission,
                numeric_turbocharging,
                numeric_brake_valve,
                price_wheel,
                price_door,
                price_trunk,
                price_hood,
                price_headlights,
                price_battery,
                price_transmission,
                price_turbocharging,
                price_brake_valve);
        cout << endl;
        cout << "Общая стоимость машины: " << car.carPrice() << endl;
    
    
}
