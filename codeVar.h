#ifndef H_CODE_VAR
#define H_CODE_VAR

#define NB_VAR  10

#define UNKNW -1
// Commands name
#define G 0
#define M 1
#define S 2
#define F 3

// axis
#define X 4
#define Y 5
#define Z 6

// For circles
#define I 7
#define J 8
#define K 9

// Custom commands
#define S 10 

uint8_t commandOfChar(char c) {
  switch c {
    case 'G' : return G;
    case 'M' : return M;
    case 'S' : return S;
    case 'F' : return F;
    case 'X' : return X;
    case 'Y' : return Y;
    case 'Z' : return Z;
    case 'I' : return I;
    case 'J' : return J;
    case 'K' : return K;
    case 'S' : return S;
    default : return UNKNW;
  }
}

#endif