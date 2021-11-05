/*
CEC 470 Group Project
Decoder
Group Members: Callan Bailey, Benigno Digon, Charles Gilmore

*/


#define HALF_OPCODE 0x19

void fetchNextInstruction(void);
void executeNextInstruction(void);

unsigned char memory[65536];
unsigned char ACC = 0;
unsigned char IR = 0;
unsigned char MAR = 0;
unsigned char PC = 0;

int main(int argc, char* argv[]){
    //load memory, maybe make it a function

    while(memory[PC] != HALF_OPCODE){
        fetchNextInstruction();
        executeNextInstruction();
    }
    return 0;
}

void fetchNextInstruction(){
    IR = memory[PC];

    //math operator
    if((IR & 0x80) == 0x80){
        //operand
        //register
        //memory
    }
    //memory
    else if((IR & 0xF0)==0x0){
        //store 
        //load
    }
    //branch function
    else if((IR & 0xF8) == 0x10){
        PC+=3;
    }
    //special or illegal opcode
    else{
        //nop
        //halt
        //illegal opcode
    }




}
void executeNextInstruction(){
    //code here
    //math operations
        // AND 000
        // OR 001
        // XOR 010
        // ADD 011
        // SUB 100
        // INC 101
        // DEC 110
        // NOT 111


        //indirect 00
        //ACC 01
        //MAR 10
        //memory 11

        //source
        //MAR 00
        //ACC 01
        //constant 10
        //memory 11

    //memory operations
        // STORE
        // LOAD

    //branch/jump
        // BRA
        // BRZ
        // BNE
        // BLT
        // BLE
        // BGT
        // BGE

    //special
        // NOP
        // HALT
        // OTHER

}