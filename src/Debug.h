#ifndef DEBUG_H
#define DEBUG_H


//Optional serial debug mode flag
#define DEBUG
#ifdef DEBUG
 #define DEBUG_PRINT(x)  Serial.println (F(x))
#else
 #define DEBUG_PRINT(x)
#endif


#endif
