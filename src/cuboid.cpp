#include"cuboid.hpp"


/*!
 *  \brief Konstruktor bezparametryczny klasy Cuboid.                                              
 *  Argumenty:                                                                
 *      Brak argumentow.                                                      
 *  Zwraca:                                                                   
 *     \post Zwraca osiem wiercholkow                                   
 */
Cuboid::Cuboid(){
int i;
double iter[4][3] = {{0,0,0},{1,0,0},{0,1,0},{1,1,0}};
for (i=0;i<4;++i){
    tops[0][i] = Vector3D(iter[i]);
    iter[i][2] = 1;
    tops[1][i] = Vector3D(iter[i]);
}
}

/*!
 *  \brief Konstruktor parametryczny klasy Cuboid.                                              
 *  Argumenty:                                                                
 *      \param[in] tab - tablica 4x2 typu Vector3D                                                      
 *  Zwraca:                                                                   
 *     \post Zwraca osiem wiercholkow zadanych przez program                                  
 */
Cuboid::Cuboid(Vector3D const (&tab)[2][4]){
int i;
for (i=0;i<4;++i){
    tops[i][0] = tab[i][0];
    tops[i][1] = tab[i][1];
}
}

void Cuboid::get_cub(Vector3D (&tab)[2][4]) const{
    int i;
    for (i=0;i<4;++i){
        tab[0][i] = tops[0][i];
        tab[1][i] = tops[1][i];
    }
}


/*!
 *  \brief Przeciazenie operatora <<                                                 
 *  Argumenty:                                                                
 *      \param[in] out - strumien wyjsciowy,                                             
 *      \param[in] Cub - prostopadloscian.                                                      
 */
std::ostream &operator<<(std::ostream &out, Cuboid const &Cub){
        out.precision(10);
    Vector3D vecs[2][4];
    Cub.get_cub(vecs);
    out << "Wierzcholek A: " << std::endl << vecs[0][0] << std::endl;
    out << "Wierzcholek B: " << std::endl << vecs[0][1] << std::endl;
    out << "Wierzcholek C: " << std::endl << vecs[0][2] << std::endl;
    out << "Wierzcholek D: " << std::endl << vecs[0][3] << std::endl;
    out << "Wierzcholek E: " << std::endl << vecs[1][0] << std::endl;
    out << "Wierzcholek F: " << std::endl << vecs[1][1] << std::endl;
    out << "Wierzcholek G: " << std::endl << vecs[1][2] << std::endl;
    out << "Wierzcholek H: " << std::endl << vecs[1][3] << std::endl;

    return out;
}