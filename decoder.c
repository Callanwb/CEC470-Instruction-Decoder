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
    //code here
    //check operator
        //math
        //memory
        //branch/jump
        //special 


}
void executeNextInstruction(){
    //code here
    //math operations
        // AND
        // OR
        // XOR
        // ADD
        // SUB
        // INC
        // DEC
        // NOT

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