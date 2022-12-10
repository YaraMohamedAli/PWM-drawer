#ifndef MCAL_MEXTI_MEXTI_INTERFACE_H_
#define MCAL_MEXTI_MEXTI_INTERFACE_H_

/*Function Prototype*/

void MEXTI0_Init();
void MEXTI1_Init();
void MEXTI2_Init();

void MEXTI_Callback(void(*Loc_PtrToFunc)(void));

#endif /* MCAL_MEXTI_MEXTI_INTERFACE_H_ */
