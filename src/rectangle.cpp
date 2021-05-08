#include "rectangle.hpp"
/*!
 *  \brief Konstruktor klasy Rectangle.                                              
 *  Argumenty:                                                                
 *      Brak argumentow.                                                      
 *  Zwraca:                                                                   
 *     \post Zwraca cztery wierzcholki prostokata                                 
 */
Rectangle::Rectangle()
{
    double iter[SIZE];
    int i;
    iter[0]=1.0;iter[1]=1.0;
    for (i=2;i<SIZE;++i)
        iter[i]=0.0;
    top[0] = Vector2D(iter);
    iter[1]=-1.0; top[1]=Vector2D(iter);
    iter[0]=-1.0; top[2]=Vector2D(iter);
    iter[1]=1.0; top[3]=Vector2D(iter);
}
/*!
 *  \brief Konstruktor klasy Rectangle.                                              
 *  Argumenty:                                                                
 *      \param[in] tab[4] - tablica wektorow reprezentujacych polozenie         
 *                       wierzcholkow                                          
 *  Zwraca:                                                                   
 *      \param[out] tab - Cztery wierzcholki prostokata opisane przez podane wektory    
 */
Rectangle::Rectangle(Vector2D const (&tab)[4])
{
    int i;
    for (i=0;i<4; ++i){
        top[i]=tab[i];
    }

    Rectangle a=*this;
    if (!a.check_rec()){
        Rectangle a;    
        *this = a;
    }

}

/*!
 *  \brief Destruktor klasy Rectangle.                                               
 *  Argumenty:                                                                
 *      Brak argumentow.                                                      
 *  Zwraca:                                                                   
 *      \post Usuwa prostokat z pamieci                                             
 */
Rectangle::~Rectangle(){
    //std::cout<<"Deleting rectangle"<<std::endl;
}


/*!
 *  \brief Funkcja przesuniecia prostokata o wektor                                  
 *  Argumenty:                                                                
 *      \param[in] tran - wektor przesuniecia                                                   
 *  Zwraca:                                                                   
 *      \param[out] translated - Prostokat z przesunietymi wierzcholkami o zadany wektor               
 */
Rectangle Rectangle::translation(Vector2D const &tran) const
{
    Rectangle translated;
    int i;
    for (i=0;i<4;++i){
        translated.top[i] = top[i] + tran;
    }

    return translated;
}

/*!
 *  \brief Funkcja przesuniecia prostokata o wektor                                  
 *  Argumenty:                                                                
 *      brak                                                                  
 *  Zwraca:                                                                   
 *      \param[out] translated - Prostokat z przesunietymi wierzcholkami o zadany wektor               
 */
Rectangle Rectangle::translation() const
{
    Rectangle translated;
    Vector2D tran;
    int i;
    std::cin.ignore(100000, '\n');
    std::cout<<"Wprowadz wspolrzedne wektora translacji w postaci dwoch liczb\n" 
             <<"tzn. wspolrzednej x oraz wspolrzednej y.";
    std::cin>>tran;
    for (i=0;i<4;++i){
        translated.top[i] = top[i] + tran;
    }

    return translated;
}
/*!
 *  \brief Funkcja zwracajaca wierzcholki prostokata (przypisuje je zmiennym)        
 *  Argumenty:                                                                
 *      \param [in] tab - tablica wektorow do ktorej zwracane sa wierzcholki prostokata                                       
 *  Zwraca:                                                                   
 *      \param[out] tab - Zmienia wartosci wektorow z wejscia                                   
 */
void Rectangle::get_rect( Vector2D (&tab)[4]) const
{
    int i;
    for (i=0;i<4;i++){
        tab[i]=top[i];
    }
}
/*!
 *  \brief Przeciazenie operatora <<                                                 
 *  Argumenty:                                                                
 *      \param[in] out - strumien wejsciowy,                                             
 *      \param[in] Rec - prostokat.                                                      
 */
std::ostream &operator<<(std::ostream &out, Rectangle const &Rec)
{
    out.precision(10);
    Vector2D vecs[4];
    Rec.get_rect( vecs);
    out << "Wierzcholek A: " << std::endl << vecs[0] << std::endl;
    out << "Wierzcholek B: " << std::endl << vecs[1] << std::endl;
    out << "Wierzcholek C: " << std::endl << vecs[2] << std::endl;
    out << "Wierzcholek D: " << std::endl << vecs[3] << std::endl;

    return out;
}

/*!
 * \brief Obrot prostokata o kat theta wokol srodka ukladu wspolrzednych             
 * Argumenty:                                                                 
 *      brak                                                                  
 * Zwraca:                                                                    
 *      \param[out] rotated - obrocony prostokat                                                    
 */
Rectangle Rectangle::rotate() const{
    double theta;
    Rectangle rotated;
    std::cin.ignore(100000, '\n');
    std::cout<<"Podaj kat obrotu w stopniach: " << std::endl;
    std::cin>> theta;
    rotated.top[0] = top[0].rotate(theta);
    rotated.top[1] = top[1].rotate(theta);
    rotated.top[2] = top[2].rotate(theta);
    rotated.top[3] = top[3].rotate(theta);

    return rotated;
}

/*!
 * \brief Obrot prostokata o kat theta wokol srodka ukladu wspolrzednych            
 * Argumenty:                                                                 
 *      \param[in] theta - kat obrotu                                         
 * Zwraca:                                                                    
 *      \param[out] rotated - obrocony prostokat                              
 */
Rectangle Rectangle::rotate(const double &theta) const{
    Rectangle rotated;
    
    rotated.top[0] = top[0].rotate(theta);
    rotated.top[1] = top[1].rotate(theta);
    rotated.top[2] = top[2].rotate(theta);
    rotated.top[3] = top[3].rotate(theta);

    return rotated;
}
/*!
 * \brief Sprawdza czy przeciwlegle boki prostokata sa rownej dlugosci               
 * Argumenty:                                                                 
 *      \param[in] vecs - tablica 4 wektorow reprezentujaca boki prostokata                                                                  
 * Zwraca:                                                                    
 *      \retval true - prostokat poprawny 
 *      \retval false - prostokat niepoprawny
 */
bool Rectangle::check_len_opp(Vector2D const (&vecs)[4]) const{
double len[4];
int i,j;
for (i=0;i<4;++i){
    len[i]=vecs[i].get_len();
}
if (!(len[0] == len[2]) && (len[1] == len[3])){
    std::cerr << "ERROR: przeciwlegle boki nie sa rowne!" << std::endl;
    return 0;
}
j=0;
if(len[0]!=len[1]){
if(!(len[0]>len[1]))    j++;
std::cout << "Dluzsze przeciwlegle boki sa sobie rowne" << std::endl
          << "Dlugosc pierwszego boku: " << len[j] << std::endl
          << "Dlugosc drugiego boku: " << len[j+2] << std::endl << std::endl;
if(!(len[0]>len[1]))    j--;
std::cout << "Krotsze przeciwlegle boki sa sobie rowne" << std::endl
          << "Dlugosc pierwszego boku: " << len[j] << std::endl
          << "Dlugosc drugiego boku: " << len[j+2] << std::endl << std::endl;
}
else std::cout << "Dany prostokat ma wszystkie boki rowne. Dlugosci bokow to:" 
  << std::endl << len[0] << std::endl << len[1] <<std::endl << len[2]
  << std::endl << len[3] << std::endl << std::endl;
return 1;
}

/*!
 * \brief Sprawdza czy wszystkie katy prostokata sa proste                           
 * Argumenty:                                                                 
 *      brak                                                                  
 * Zwraca:                                                                    
 *      \retval true - prostokat poprawny 
 *      \retval false - prostokat niepoprawny         
 */
bool Rectangle::check_angle_rec(Vector2D const (&vecs)[4]) const{
    double A,B,C,D;
    A = vecs[0].get_slope_angle() - vecs[3].get_slope_angle();
    B = vecs[1].get_slope_angle() - vecs[0].get_slope_angle();
    C = vecs[2].get_slope_angle() - vecs[1].get_slope_angle();
    D = vecs[3].get_slope_angle() - vecs[2].get_slope_angle();
    //std::cout << A <<" "<< B << " "<< C <<" "<< D <<   std::endl;
    if (!(check_angle_straight(A) && check_angle_straight(B) 
 && check_angle_straight(C) && check_angle_straight(D))){
        std::cerr<<"Error: katy prostokata nie sa proste!"<<std::endl;
             return 0;
    }   
    std::cout << "Wszystkie katy prostokata sa proste." << std::endl << std::endl;
    return 1;
}

/*!
 * \brief Sprawdza czy wpojedynczy kat jest prosty                                   
 * Argumenty:                                                                 
 *      \param[in] ang - kat do sprawdzenia                                                                
 * Zwraca:                                                                    
 *      \retval true - prostokat poprawny 
 *      \retval false - prostokat niepoprawny                                
 */
bool Rectangle::check_angle_straight(double ang) const{
    double a = abs(ang);
    if (!(a == 90 || a == 270))
        return 0;
    return 1;
}
/*!
 * \brief Sprawdza czy przeciwlegle boki prostokata sa oraz czy katy sa proste       
 * Argumenty:                                                                 
 *      brak                                                                  
 * Zwraca:                                                                    
 *      \retval true - prostokat poprawny 
 *      \retval false - prostokat niepoprawny
 */
bool Rectangle::check_rec() const{
Vector2D sides[4];
//double angA,angB,angC,angD;
int i=1;
sides[0] = top[i]-top[i-1]; i++;
sides[1] = top[i]-top[i-1]; i++;
sides[2] = top[i]-top[i-1]; i++;
sides[3] = top[0]-top[i-1]; i++;

if (!check_len_opp(sides))
    return 0;

if(!check_angle_rec(sides))
    return 0;
return 1;
}
/*!
 * \brief Sprawdza czy przeciwlegle boki prostokata sa oraz czy katy sa proste       
 * Argumenty:                                                                 
 *      brak                                                                  
 * Zwraca:                                                                    
 *      \retval true - prostokat poprawny 
 *      \retval false - prostokat niepoprawny
 */
Rectangle Rectangle::rotation_n_times(){
    Rectangle tmp;
    double ang, ang_rep;
    int rep;
    std::cout<<"Podaj wartosc kata obrotu w stopniach" << std::endl;
    std::cin>>ang;
    std::cout<<"Ile razy operacja obrotu ma byc powtorzona?" << std::endl;
    std::cin>>rep;
    double dorep = rep;
    ang_rep = ang*dorep;
    tmp = this->rotate(ang_rep);
    tmp.check_rec();
    return tmp;
}

/*!
 * \brief Kieruje wspolrzedne prostokata na strumien wyjsciowy                       
 * Argumenty:                                                                 
 *      \param[in] out - strumien wyjsciowy                                                                  
 * Zwraca:                                                                    
 *      \param[out] out - strumien wyjsciowy z zapisanymi wspolrzednymi                                                                 
 */
void Rectangle::RectangleToStdout(std::ostream &out)
{
    int i;
    for (i=0;i<4;++i){
        out<<std::setw(10) << std::fixed << std::setprecision(10) << top[i][0] <<" " << top[i][1] << std::endl;
    }
    out<<top[0][0] <<" " << top[0][1] << std::endl;
}

/*!
 * \brief Przyklad zapisu wspolrzednych zbioru punktow do pliku, z ktorego
 * dane odczyta program gnuplot i narysuje je w swoim oknie graficznym.
 * \param[in] sNazwaPliku - nazwa pliku, do którego zostana zapisane
 *                          wspolrzędne punktów.
 * \param[in] Przesuniecie - ten parameter jest tylko po to, aby pokazać
 *                          mozliwosc zmiany wspolrzednych i prostokata
 *                          i zmiane jego polozenia na okienku graficznym
 *                         rysownym przez gnuplota.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
bool Rectangle::RectangleToFile(const char *sNazwaPliku)
{
       std::ofstream StrmPlikowy;

       StrmPlikowy.open(sNazwaPliku);
       if (!StrmPlikowy.is_open())
       {
              std::cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << std::endl
                        << ":(  nie powiodla sie." << std::endl;
              return false;
       }

       this->RectangleToStdout(StrmPlikowy);

       StrmPlikowy.close();
       return !StrmPlikowy.fail();
}
/*!
 * \brief Wyswietla prostokat w GNUplocie                                            *
 * Argumenty:                                                                 *
 *      brak                                                                  *
 * Zwraca:                                                                    *
 *      brak                                                                  *
 */
void Rectangle::PrintRectangle(){
    PzG::LaczeDoGNUPlota Lacze; // Ta zmienna jest potrzebna do wizualizacji

       Lacze.DodajNazwePliku("../datasets/prostokat.dat", PzG::RR_Ciagly, 2);

       Lacze.DodajNazwePliku("../datasets/prostokat.dat", PzG::RR_Punktowy, 2);

       Lacze.ZmienTrybRys(PzG::TR_2D);
           this->RectangleToStdout(std::cout);
       if (!this->RectangleToFile("../datasets/prostokat.dat"))
              std::cerr << "ERROR" << std::endl;
       Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
       std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
       std::cin.ignore(100000, '\n');
}
/*!
 *  \brief Przeciążenie == prostokata                                                         
 *  Argumenty:                                                               
 *      \param[in] this - prostokat, ktora porownujemy                   
 *      \param[in] tmp - prostokat, z ktora porownujemy                                                          
 *  Zwraca:                                                                  
 *      \retval true - jesli sa rowne
 *      \retval false - jesli nie sa                
 */
bool Rectangle::operator == (const Rectangle &rec) const{
    int i;
    for (i=0;i<4;++i){
        if (!(top[i]==rec.top[i]))
            return 0;
    }
    return 1;
}

