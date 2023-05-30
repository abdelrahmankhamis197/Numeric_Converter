
#ifndef CALC_H_
#define CALC_H_

void CALC_Main_Init(void);

void CALC_Main_Runnable(void);

u16 CALC_ScanNum(void);

u16 CALC_ScanHexNum(void);

u16 CALC_ScanBinNum(void);

void CALC_DecHandeller(void);

void CALC_HexHandeller(void);

void CALC_BinHandeller(void);

#endif /* CALC_H_ */