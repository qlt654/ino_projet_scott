//
// Alphabet.hpp
// ino_projet_scott
//
// Created by qlt654 on 21/06/2018.
//
//

/**
 * Encodage de l'aphabet morse en hexadecimal.
 * Les valeurs sont enregistrées en directive de préprocesseur pour limiter
 * l'utilisation de la mémoire.
 */


#ifndef ALPHABET_HPP
#define ALPHABET_HPP


#define MASK_1_TA 0X3
#define MASK_2_TA 0XC
#define MASK_3_TA 0X30
#define MASK_4_TA 0XC0
#define MASK_5_TA 0X300
#define MASK_6_TA 0XC00

#define MASK_1_TI 0X1
#define MASK_2_TI 0X4
#define MASK_3_TI 0X10
#define MASK_4_TI 0X40
#define MASK_5_TI 0X100
#define MASK_6_TI 0X400


/*
#define CHAR_A	0XD
#define CHAR_B	0X57
#define CHAR_C	0X77
#define CHAR_D	0X17
#define CHAR_E	0X1
#define CHAR_F	0X75
#define CHAR_G	0X1F
#define CHAR_H	0X55
#define CHAR_I	0X5
#define CHAR_J	0XFD
#define CHAR_K	0X37
#define CHAR_L	0X5D
#define CHAR_M	0XF
#define CHAR_N	0X7
#define CHAR_O	0X3F
#define CHAR_P	0X7D
#define CHAR_Q	0XDF
#define CHAR_R	0X1D
#define CHAR_S	0X15
#define CHAR_T	0X3
#define CHAR_U	0X35
#define CHAR_V	0XD5
#define CHAR_W	0X3D
#define CHAR_X	0XD7
#define CHAR_Y	0XF7
#define CHAR_Z	0X5F

#define CHAR_0	0X3FF
#define CHAR_1	0X3FD
#define CHAR_2	0X3F5
#define CHAR_3	0X3D5
#define CHAR_4	0X355
#define CHAR_5	0X155
#define CHAR_6	0X157
#define CHAR_7	0X15F
#define CHAR_8	0X17F
#define CHAR_9	0X1FF

#define CHAR_POINT	0XDDD
#define CHAR_VIRGULE	0XF5F
#define CHAR_INTEROG	0X5F5
*/
//#define CHAR_APOSTRO	0
//#define CHAR_EXCLAMA	0
//#define CHAR_PAROUVR	0
//#define CHAR_PARFERM	0
//#define CHAR_&	0
//#define CHAR_:	0

struct alphab {
  char car ;
  unsigned int hex;
} ;


const alphab alpha[57] {
{'a' , 0XD  } ,
{'b' , 0X57 } ,
{'c' , 0X77 } ,
{'d' , 0X17 } ,
{'e' , 0X1  } ,
{'f' , 0X75 } ,
{'g' , 0X1F } ,
{'h' , 0X55 } ,
{'i' , 0X5  } ,
{'j' , 0XFD } ,
{'k' , 0X37 } ,
{'l' , 0X5D } ,
{'m' , 0XF  } ,
{'n' , 0X7  } ,
{'o' , 0X3F } ,
{'p' , 0X7D } ,
{'q' , 0XDF } ,
{'r' , 0X1D } ,
{'s' , 0X15 } ,
{'t' , 0X3  } ,
{'u' , 0X35 } ,
{'v' , 0XD5 } ,
{'w' , 0X3D } ,
{'x' , 0XD7 } ,
{'y' , 0XF7 } ,
{'z' , 0X5F }
};
/*
unsigned int alpha[57][2] = {
{'a' , 0XD},
{'b' , 0X57},
{'c' , 0X77}
} ;*/




#endif //ALPHABET_HPP
