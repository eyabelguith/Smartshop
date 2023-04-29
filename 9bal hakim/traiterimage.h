
#include <iostream>
#include <fstream>
using namespace std;
#include <QImage>

typedef unsigned char byte;
typedef double PIXEL;

#ifndef TRAITERIMAGE_H
#define TRAITERIMAGE_H

class TraiterImage
{
protected:

 byte **m_ppImage;    // Matrice Image

 PIXEL **m_normex;    // Matrice du  masque Horizantale (x)
 PIXEL **m_normey;    // Matrice du  masque Verticale (y)
 PIXEL **m_norme;     // Matric de la  norme  du  gradient

 byte **m_buffer;     // Buffer Image
 int m_nWidth ;       // langueurImage
 int m_nHeight ;      // largeur Image

 // methode  d'Allocation  et de liberation  de memoire
 void Allouer( );
 void Liberer( );

public :

TraiterImage( ) ;

TraiterImage( int , int  );

~TraiterImage( );

bool isNULL();

int Width( ) ;  // langeur d'image
int Height( );  // largeur d'image

void affiche();



void seuil(int,int );

// detection des contours

void maskvert(void);
void maskhori(void);

// Normes  du Gradient

void normex(int);
void normey(int);
void norme(int);

// Transfer buffer methods

void transfertx(void);
void transferty(void);
void transfert_n(void);

//  recuperer la  ligne

 byte* GetLine( int );



// Transfer Methods between QImage and TraiterImage

void transfert_to_qim(QImage*);
void transfert_to_exim(QImage*);

// Transformer une  image couleur  en luminance ( noir  et  blanc)

void rgb_to_lum(int);

// Suppression de bruit

void gaussian(int);
void fenetrage(int,int, int, int, double);
void seuillage(int,int,  double);
void binarisation(int,int, int);
void binarisation_par_intervalle(int,int, int, int);
void seuillage_par_intervalle(int,int, int , int, double);

void inversion(int);
void moyenneur(int);
void mediane(int,int);
byte tri(byte* , int);

// recuperer le Buffer

byte* get_buffer(void) ;

};
#endif // TRAITERIMAGE_H
