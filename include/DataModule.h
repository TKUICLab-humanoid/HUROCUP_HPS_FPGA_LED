#ifndef DATAMODULE_H_
#define DATAMODULE_H_

/******************* Define******************************/
#define DataModule_debug    /* Turn debugging on */
/********************************************************/

/******************* Parameter **************************/

/******************* Include libarary*********************/
#include <stdio.h>
#include <fstream>
#include <vector>
#include <map>
#include <iostream>
/********************************************************/

/******************* Include module**********************/
#include "Inverse_kinematic.h"
/********************************************************/

/******************** Function **************************/
void RS232DataInterrupt( void* context, alt_u32 id );
void Flash_Access(void);
void MotionExecute();

/********************************************************/

class Datamodule
{
public:
    Datamodule();
    ~Datamodule();

    void load_database();
    void update_database();
    void motion_execute();
    void set_stand();

    std::string DtoS(double value);
	std::map<std::string, std::vector<double>> map_motor;       
    void saveData();

    unsigned char datamodule_cmd_;
    bool motion_execute_flag_;
    int totalangle_[21];
    int totalspeed_[21];

private:
    bool update_database_flag_;
    int database_[21];
    int name_cont_;
    
};

#endif /*DATAMODULE_H_*/
