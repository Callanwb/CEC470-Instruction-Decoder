/*
CEC 470 Group Project
Decoder
Group Members: Callan Bailey, Benigno Digon, Charles Gilmore
*/

#define HALT_OPCODE 0x19

void fetchNextInstruction(void);
void executeNextInstruction(void);

unsigned char memory[65536];
unsigned char ACC = 0; //8 bit
unsigned char IR = 0;  //8 bit
unsigned char MAR = 0; //16 bit
unsigned char PC = 0;  //16 bit

int main(int argc, char *argv[])
{
    //load memory, maybe make it a function

    while (memory[PC] != HALT_OPCODE)
    {
        fetchNextInstruction();
        executeNextInstruction();
    }
    return 0;
}

void fetchNextInstruction()
{
    //store instruction in IR
    IR = memory[PC];

    //will need to incrememnt PC in this part depending on the instruction, will either increment by 1, 2, 3 bytes

    //using big endian check last spot first

    //math operator
    if ((IR & 0x80) == 0x80)
    {
        //one or two operand
        if ((IR & 0x70) >> 4 <= 4)
        {
            switch (IR & 0x0F)
            {
            //indirect MAR pointer indirect MAR pointer
            case (0b0000):
                PC++;
                break;
            //indirect MAR pointer accumulator ACC
            case (0b0001):
                PC++;
                break;
            //indirect MAR pointer constant
            case (0b0010):
                PC += 2;
                break;
            //indirect MAR pointer memory
            case (0b0011):
                PC += 3;
                break;
            //accumulator ACC indirect MAR pointer
            case (0b0100):
                PC++;
                break;
            //accumulator ACC accumulator ACC
            case (0b0101):
                PC++;
                break;
            //accumulator ACC constant
            case (0b0110):
                PC += 2;
                break;
            //accumulator ACC memory
            case (0b0111):
                PC += 3;
                break;
            //register MAR indirect MAR pointer
            case (0b1000):
                PC++;
                break;
            //register MAR accumulator ACC
            case (0b1001):
                PC++;
                break;
            //register MAR constant
            case (0b1010):
                PC += 2;
                break;
            //regiseter MAR memory
            case (0b1011):
                PC += 3;
                break;
            //memory indirect MAR pointer
            case (0b1100):
                PC += 3;
                break;
            //memory accumulator ACC
            case (0b1101):
                PC += 3;
                break;
            //memory constant
            case (0b1110):
                PC += 4;
                break;
            //memory memory
            case (0b1111):
                PC += 5;
                break;
            }
        }
        //not on register
        else if ((IR & 0x0C) != 0b1100)
        {
            PC++;
        }
        //not on memory
        else
        {
            PC += 3;
        }
    }
    //memory
    else if ((IR & 0xF0) == 0)
    {
        switch(IR & 0x0F)
        {
        case(0):// store ACC -> [op] (2 bytes of operand)
            PC += 3;
            break;
        case(1): //store ACC -> op ;this isnt a valid op, need to clarify w/ prof
            
            break;
        case(2): //store ACC -> [MAR] (0 bytes of operand)
            PC++;
            break;
        case(4): //store MAR -> [op] (2 bytes of operand)
            PC += 3;
            break;
        case(5): //store MAR -> op ;this isnt a valid op, need to clarify w/ prof
            
            break;
        case(6): //store MAR -> [MAR] (0 bytes of operand)
            PC++;
            break;
        case(8): //load [op] -> ACC (2 bytes of operand)
            PC += 3;
            break;
        case(9): //load op -> ACC (1 byte of operand)
            PC += 2;
            break;
        case(10): //load [MAR] -> ACC (0 bytes of operand)
            PC++;
            break;
        case(12): //load [op] -> MAR (2 bytes of operand)
            PC += 3;
            break;
        case(13): //load op -> MAR (2 bytes of operand)
            PC += 3;
            break;
        case(14): //load [MAR] -> MAR (0 bytes of operand)
            PC++;
            break;
        }
    }   
    //branch function
    else if ((IR & 0xF8) == 0x10)
    {
        //increment PC
    }
    //special or illegal opcode
    else
    {
        //nop
        //halt
        //illegal opcode
    }
}
void executeNextInstruction()
{
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
    /*else*/ if ((IR & 0xF0) == 0)
    {
        switch(IR & 0x0F)
        {
        case(0):// store ACC -> [op] (2 bytes of operand)
            memory[(memory[PC - 2] << 8) + memory[PC - 1]] = ACC;
            break;
        case(1): //store ACC -> op ;this isnt a valid op, need to clarify w/ prof
            
            break;
        case(2): //store ACC -> [MAR] (0 bytes of operand)
            memory[MAR] = ACC;
            break;
        case(4): //store MAR -> [op] (2 bytes of operand)
            memory[(memory[PC - 2] << 8) + memory[PC - 1]] = MAR >> 8;//MSB
            memory[(memory[PC - 2] << 8) + memory[PC - 1] + 1] = MAR - ((MAR >> 8) << 8);//LSB
            break;
        case(5): //store MAR -> op ;this isnt a valid op, need to clarify w/ prof
            
            break;
        case(6): //store MAR -> [MAR] (0 bytes of operand)
            memory[MAR] = MAR >> 8;//MSB
            memory[MAR + 1] = MAR - ((MAR >> 8) << 8);//LSB
            break;
        case(8): //load [op] -> ACC (2 bytes of operand)
            ACC = memory[(memory[PC - 2] << 8) + memory[PC - 1]];
            break;
        case(9): //load op -> ACC (1 byte of operand)
            ACC = memory[PC - 1];
            break;
        case(10): //load [MAR] -> ACC (0 bytes of operand)
            ACC = memory[MAR];
            break;
        case(12): //load [op] -> MAR (2 bytes of operand)
            MAR = memory[memory[PC - 2]];//MSB
            MAR = MAR << 8;
            MAR += memory[memory[PC - 1]];//LSB
            break;
        case(13): //load op -> MAR (2 bytes of operand)
            MAR = memory[PC - 2];//MSB
            MAR = ACC << 8;
            MAR += memory[PC - 1];//LSB
            break;
        case(14): //load [MAR] -> MAR (0 bytes of operand)
            MAR = memory[MAR];//MSB
            MAR = MAR << 8;
            MAR += memory[MAR + 1];//LSB
            break;
        }
    }
    // Branch/Jumps:
    // If the most significant five bits are 00010, then the opcode represents an unconditional or
    // conditional branch or jump. The opcode is always followed by a 16-bit operand that serves as
    // the memory address.
    switch (IR & 0x07)
    {
    // BRA = 0b000 (Unconditional Branch/Branch always)
    case (0b00010000):
        (memory[PC + 1] << 8) + memory[PC + 2];
        break;
    // BRZ = 0b001 (Branch if ACC = 0)
    case (0b00010001):
        break;
    // BNE = 0b010 (Branch if ACC != 0)
    case (0b00010010):
        break;
    // BLT = 0b011 (Branch if ACC < 0)
    case (0b00010011):
        break;
    // BLE = 0b100 (Branch if ACC <= 0)
    case (0b00010100):
        break;
    // BGT = 0b101 (Branch if ACC > 0)
    case (0b00010101):
        break;
    // BGE = 0b110 (Branch if ACC >= 0)
    case (0b00010110):
        break;
    }
    // Special Opcodes

    // No Operation (NOP) - DO NOTHING
    // fetchNextInstruction() increment PC by 1
    if (IR == 0x18)
    {
    }

    // HALT/ Stop processor
    else if (IR == HALT_OPCODE)
    {
        // Halt? exit()? stop()? sleep()?
        sleep();
    }
    // Illegal
    else
    {
        printf("Illegal Opcode!");
    }
}