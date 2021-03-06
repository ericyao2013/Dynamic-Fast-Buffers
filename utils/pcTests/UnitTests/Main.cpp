#include "dfb/TypecodeAPI.h"
#include "dfb/BytecodeAPI.h"
#include "dfb/SerializerAPI.h"
#include "dfb/CommonData.h"
#include "fastcdr/FastCdr.h"
#include "fastcdr/FastBuffer.h"
#include "fastcdr/exceptions/Exception.h"
#include "dfb/exceptions/WrongParamException.h"
#include <iostream>
#include <exception>
#include <cstdint>

using namespace std;

bool generateBytecodeWhiteBox02()
{
	try{
		DynamicFastBuffers::BytecodeAPI::generateBytecode(NULL, DynamicFastBuffers::SERIALIZE);
		return false;
	}catch (DynamicFastBuffers::WrongParamException e){
		return true;
	}
}

bool addMembersWhiteBox01()
{
	DynamicFastBuffers::Typecode *tcStruct;
	DynamicFastBuffers::Typecode *tcInteger;
	DynamicFastBuffers::Typecode *tcShort;
	DynamicFastBuffers::Typecode *tcArray;
	tcArray = DynamicFastBuffers::TypecodeAPI::createArray(DynamicFastBuffers::TypecodeAPI::createDouble(), 2, 4, 4, 0);
	tcInteger = DynamicFastBuffers::TypecodeAPI::createInteger();
	tcShort = DynamicFastBuffers::TypecodeAPI::createShort();
	tcStruct = DynamicFastBuffers::TypecodeAPI::createStruct(NULL);

	DynamicFastBuffers::TypecodeAPI::addMembers(tcStruct, tcInteger, tcArray, tcShort, tcShort, NULL);

	//
	// Comparison
	//
	bool returnValue = true;
	returnValue &= (tcStruct->getMembers()[0].getKind() == DynamicFastBuffers::TC_INTEGER);
	returnValue &= (tcStruct->getMembers()[1].getKind() == DynamicFastBuffers::TC_ARRAY);
	returnValue &= (tcStruct->getMembers()[2].getKind() == DynamicFastBuffers::TC_SHORT);
	returnValue &= (tcStruct->getMembers()[3].getKind() == DynamicFastBuffers::TC_SHORT);
	
	return returnValue;
}

bool addMembersWhiteBox02()
{
	//
	// Comparison
	//
	try{
		DynamicFastBuffers::TypecodeAPI::addMembers(NULL);
		return false;
	}catch (DynamicFastBuffers::WrongParamException e){
		return true;
	}
}

bool addMembersWhiteBox03()
{
	//
	// Comparison
	//
	try{
		DynamicFastBuffers::TypecodeAPI::addMembers(DynamicFastBuffers::TypecodeAPI::createStruct(NULL), NULL);
		return false;
	}catch (DynamicFastBuffers::NotEnoughParamsException e){
		return true;
	}
}

bool addMembersWhiteBox04()
{
	//
	// Comparison
	//
	try{
		DynamicFastBuffers::TypecodeAPI::addMembers(DynamicFastBuffers::TypecodeAPI::createInteger(), NULL);
		return false;
	}catch (DynamicFastBuffers::NotEnoughParamsException e){
		return true;
	}
}

bool addMembersWhiteBox05()
{
	//
	// Comparison
	//
	try{
		DynamicFastBuffers::TypecodeAPI::addMembers(DynamicFastBuffers::TypecodeAPI::createInteger(), DynamicFastBuffers::TypecodeAPI::createInteger());
		return false;
	}catch (DynamicFastBuffers::WrongTypeException e){
		return true;
	}
}

bool createTypeBlackBox()
{
	DynamicFastBuffers::Typecode *tcInt = DynamicFastBuffers::TypecodeAPI::createInteger();
	DynamicFastBuffers::Typecode *tcShort = DynamicFastBuffers::TypecodeAPI::createShort();
	DynamicFastBuffers::Typecode *tcLong = DynamicFastBuffers::TypecodeAPI::createLong();
	DynamicFastBuffers::Typecode *tcFloat = DynamicFastBuffers::TypecodeAPI::createFloat();
	DynamicFastBuffers::Typecode *tcDouble = DynamicFastBuffers::TypecodeAPI::createDouble();
	DynamicFastBuffers::Typecode *tcString = DynamicFastBuffers::TypecodeAPI::createString();
	DynamicFastBuffers::Typecode *tcBoolean = DynamicFastBuffers::TypecodeAPI::createBoolean();
	DynamicFastBuffers::Typecode *tcCharacter = DynamicFastBuffers::TypecodeAPI::createCharacter();
	DynamicFastBuffers::Typecode *tcArray = DynamicFastBuffers::TypecodeAPI::createArray(tcInt, 1, 5, 0);
	DynamicFastBuffers::Typecode *tcStruct = DynamicFastBuffers::TypecodeAPI::createStruct(NULL);
	DynamicFastBuffers::Typecode *tcSequence = DynamicFastBuffers::TypecodeAPI::createSequence(tcShort, 10);
	
	//
	// Comparison
	//
	bool returnValue = true;
	returnValue &= (tcInt->getKind() == DynamicFastBuffers::TC_INTEGER);
	returnValue &= (tcShort->getKind() == DynamicFastBuffers::TC_SHORT);
	returnValue &= (tcLong->getKind() == DynamicFastBuffers::TC_LONG);
	returnValue &= (tcFloat->getKind() == DynamicFastBuffers::TC_FLOAT);
	returnValue &= (tcDouble->getKind() == DynamicFastBuffers::TC_DOUBLE);
	returnValue &= (tcString->getKind() == DynamicFastBuffers::TC_STRING);
	returnValue &= (tcBoolean->getKind() == DynamicFastBuffers::TC_BOOLEAN);
	returnValue &= (tcCharacter->getKind() == DynamicFastBuffers::TC_CHARACTER);
	returnValue &= (tcArray->getKind() == DynamicFastBuffers::TC_ARRAY);
	returnValue &= (tcStruct->getKind() == DynamicFastBuffers::TC_STRUCT);
	returnValue &= (tcSequence->getKind() == DynamicFastBuffers::TC_SEQUENCE);

	return returnValue;
}

bool addMembersBlackBox01()
{
	DynamicFastBuffers::Typecode *structure = DynamicFastBuffers::TypecodeAPI::createStruct(NULL);
	DynamicFastBuffers::TypecodeAPI::addMembers(structure, DynamicFastBuffers::TypecodeAPI::createBoolean(), NULL);
	//
	// Comparison
	//
	bool returnValue = true;
	returnValue &= (structure->getKind() == DynamicFastBuffers::TC_STRUCT);
	returnValue &= (structure->getMembers()[0].getKind() == DynamicFastBuffers::TC_BOOLEAN);
	
	return returnValue;
}

bool addMembersBlackBox02()
{
	DynamicFastBuffers::Typecode *structure = DynamicFastBuffers::TypecodeAPI::createStruct(NULL);
	DynamicFastBuffers::TypecodeAPI::addMembers(structure, DynamicFastBuffers::TypecodeAPI::createBoolean(), DynamicFastBuffers::TypecodeAPI::createDouble(), NULL);
	//
	// Comparison
	//
	bool returnValue = true;
	returnValue &= (structure->getKind() == DynamicFastBuffers::TC_STRUCT);
	returnValue &= (structure->getMembers()[0].getKind() == DynamicFastBuffers::TC_BOOLEAN);
	returnValue &= (structure->getMembers()[1].getKind() == DynamicFastBuffers::TC_DOUBLE);

	return returnValue;
}

bool addMembersBlackBox03()
{
	DynamicFastBuffers::Typecode *structure = DynamicFastBuffers::TypecodeAPI::createStruct(NULL);
	DynamicFastBuffers::TypecodeAPI::addMembers(structure, DynamicFastBuffers::TypecodeAPI::createBoolean(), DynamicFastBuffers::TypecodeAPI::createDouble(), NULL);

	DynamicFastBuffers::Typecode *outerStruct;
	outerStruct = DynamicFastBuffers::TypecodeAPI::createStruct(structure, NULL);

	//
	// Comparison
	//
	bool returnValue = true;
	returnValue &= (outerStruct->getKind() == DynamicFastBuffers::TC_STRUCT);
	returnValue &= (outerStruct->getMembers()[0].getKind() == DynamicFastBuffers::TC_STRUCT);
	returnValue &= (outerStruct->getMembers()[0].getMembers()[0].getKind() == DynamicFastBuffers::TC_BOOLEAN);
	returnValue &= (outerStruct->getMembers()[0].getMembers()[1].getKind() == DynamicFastBuffers::TC_DOUBLE);
	
	return returnValue;
}

bool addMembersBlackBox04()
{
	DynamicFastBuffers::Typecode *structure1 = DynamicFastBuffers::TypecodeAPI::createStruct(NULL);
	DynamicFastBuffers::TypecodeAPI::addMembers(
		structure1, 
		DynamicFastBuffers::TypecodeAPI::createFloat(), 
		DynamicFastBuffers::TypecodeAPI::createArray(DynamicFastBuffers::TypecodeAPI::createShort(), 1, 5, 0),
		NULL
	);
	DynamicFastBuffers::Typecode *structure2 = DynamicFastBuffers::TypecodeAPI::createStruct(NULL);
	DynamicFastBuffers::TypecodeAPI::addMembers(
		structure2, DynamicFastBuffers::TypecodeAPI::createBoolean(), 
		DynamicFastBuffers::TypecodeAPI::createDouble(),
		NULL
	);

	DynamicFastBuffers::Typecode *outerStruct;
	outerStruct = DynamicFastBuffers::TypecodeAPI::createStruct(structure1, structure2, NULL);

	//
	// Comparison
	//
	bool returnValue = true;
	returnValue &= (outerStruct->getKind() == DynamicFastBuffers::TC_STRUCT);
	returnValue &= (outerStruct->getMembers()[0].getKind() == DynamicFastBuffers::TC_STRUCT);
	returnValue &= (outerStruct->getMembers()[0].getMembers()[0].getKind() == DynamicFastBuffers::TC_FLOAT);
	returnValue &= (outerStruct->getMembers()[0].getMembers()[1].getKind() == DynamicFastBuffers::TC_ARRAY);
	returnValue &= (outerStruct->getMembers()[1].getKind() == DynamicFastBuffers::TC_STRUCT);
	returnValue &= (outerStruct->getMembers()[1].getMembers()[0].getKind() == DynamicFastBuffers::TC_BOOLEAN);
	returnValue &= (outerStruct->getMembers()[1].getMembers()[1].getKind() == DynamicFastBuffers::TC_DOUBLE);

	return returnValue;
}

bool generateBytecodeBlakBox01()
{
	DynamicFastBuffers::Bytecode *bc;
	bc = DynamicFastBuffers::BytecodeAPI::generateBytecode(
		DynamicFastBuffers::TypecodeAPI::createLong(), 
		DynamicFastBuffers::SERIALIZE
	);
	//
	// Comparison
	//
	bool returnValue = true;
	returnValue &= (bc->getBytecode()->size() == 1);
	
	return returnValue;
}

bool generateBytecodeBlakBox02()
{
	DynamicFastBuffers::Typecode *structure = DynamicFastBuffers::TypecodeAPI::createStruct(NULL);
	DynamicFastBuffers::TypecodeAPI::addMembers(structure, DynamicFastBuffers::TypecodeAPI::createBoolean(), DynamicFastBuffers::TypecodeAPI::createDouble(), NULL);
	DynamicFastBuffers::Bytecode *bc;
	bc = DynamicFastBuffers::BytecodeAPI::generateBytecode(
		structure,
		DynamicFastBuffers::SERIALIZE
	);
	//
	// Comparison
	//
	bool returnValue = true;
	returnValue &= (bc->getBytecode()->size() == 2);
	
	return returnValue;
}

//
// Structures for proving next functions
//
struct inner
{
	char att1;
	char att2;
	short att3;
};

struct outer
{
	float att1;
	string att2;
	int32_t att3;
	inner att4;
};

bool serializeBlackBox01(eprosima::FastCdr *cdrp)
{

	int size = 0;
	size += DynamicFastBuffers::TypecodeAPI::checkSerializedDataSize(
		DynamicFastBuffers::TypecodeAPI::createInteger());
	size += DynamicFastBuffers::TypecodeAPI::checkSerializedDataSize(
		DynamicFastBuffers::TypecodeAPI::createShort());
	size += DynamicFastBuffers::TypecodeAPI::checkSerializedDataSize(
		DynamicFastBuffers::TypecodeAPI::createFloat());
	size += DynamicFastBuffers::TypecodeAPI::checkSerializedDataSize(
		DynamicFastBuffers::TypecodeAPI::createDouble());
	size += DynamicFastBuffers::TypecodeAPI::checkSerializedDataSize(
		DynamicFastBuffers::TypecodeAPI::createLong());
	size += DynamicFastBuffers::TypecodeAPI::checkSerializedDataSize(
		DynamicFastBuffers::TypecodeAPI::createString());
	size += DynamicFastBuffers::TypecodeAPI::checkSerializedDataSize(
		DynamicFastBuffers::TypecodeAPI::createCharacter());
	size += DynamicFastBuffers::TypecodeAPI::checkSerializedDataSize(
		DynamicFastBuffers::TypecodeAPI::createBoolean());

	char *buffer = (char*) malloc(size);
	eprosima::FastCdr *cdr;
	eprosima::FastBuffer *cdrBuffer;
	cdrBuffer = new eprosima::FastBuffer(buffer, size); 
	cdr = new eprosima::FastCdr(*cdrBuffer);

	DynamicFastBuffers::Bytecode *bc1;
	DynamicFastBuffers::Bytecode *bc2;
	DynamicFastBuffers::Bytecode *bc3;
	DynamicFastBuffers::Bytecode *bc4;
	DynamicFastBuffers::Bytecode *bc5;
	DynamicFastBuffers::Bytecode *bc6;
	DynamicFastBuffers::Bytecode *bc7;
	DynamicFastBuffers::Bytecode *bc8;

	bc1 = DynamicFastBuffers::BytecodeAPI::generateBytecode(DynamicFastBuffers::TypecodeAPI::createInteger(), DynamicFastBuffers::SERIALIZE);
	bc2 = DynamicFastBuffers::BytecodeAPI::generateBytecode(DynamicFastBuffers::TypecodeAPI::createShort(), DynamicFastBuffers::SERIALIZE);
	bc3 = DynamicFastBuffers::BytecodeAPI::generateBytecode(DynamicFastBuffers::TypecodeAPI::createFloat(), DynamicFastBuffers::SERIALIZE);
	bc4 = DynamicFastBuffers::BytecodeAPI::generateBytecode(DynamicFastBuffers::TypecodeAPI::createDouble(), DynamicFastBuffers::SERIALIZE);
	bc5 = DynamicFastBuffers::BytecodeAPI::generateBytecode(DynamicFastBuffers::TypecodeAPI::createLong(), DynamicFastBuffers::SERIALIZE);
	bc6 = DynamicFastBuffers::BytecodeAPI::generateBytecode(DynamicFastBuffers::TypecodeAPI::createString(), DynamicFastBuffers::SERIALIZE);
	bc7 = DynamicFastBuffers::BytecodeAPI::generateBytecode(DynamicFastBuffers::TypecodeAPI::createCharacter(), DynamicFastBuffers::SERIALIZE);
	bc8 = DynamicFastBuffers::BytecodeAPI::generateBytecode(DynamicFastBuffers::TypecodeAPI::createBoolean(), DynamicFastBuffers::SERIALIZE);
	
	//
	// Comparison
	//
	try{
		cdr->reset();
		int32_t i1 = 10;
		DynamicFastBuffers::SerializerAPI::serialize((void*) &i1, bc1, cdr); 
		short s1 = 3;
		DynamicFastBuffers::SerializerAPI::serialize((void*) &s1, bc2, cdr); 
		float f1 = 5;
		DynamicFastBuffers::SerializerAPI::serialize((void*) &f1, bc3, cdr); 
		double d1 = 3.5;
		DynamicFastBuffers::SerializerAPI::serialize((void*) &d1, bc4, cdr); 
		int64_t l1 = 22;
		DynamicFastBuffers::SerializerAPI::serialize((void*) &l1, bc5, cdr); 
		std::string str1 = "HELLO WORLD";
		DynamicFastBuffers::SerializerAPI::serialize((void*) &str1, bc6, cdr); 
		char c1 = 'A';
		DynamicFastBuffers::SerializerAPI::serialize((void*) &c1, bc7, cdr); 
		bool b1 = false;
		DynamicFastBuffers::SerializerAPI::serialize((void*) &b1, bc8, cdr); 
	}catch(exception e){
		return false;
	}
	return true;
}

bool serializeBlackBox02(eprosima::FastCdr *cdrp)
{
	inner inputStruct;
	
	inputStruct.att1 = 'A';
	inputStruct.att2 = 'B';
	inputStruct.att3 = 1000;
	
	int size = 0;
	
	

	DynamicFastBuffers::Typecode *tc = DynamicFastBuffers::TypecodeAPI::createStruct(
		DynamicFastBuffers::TypecodeAPI::createCharacter(),
		DynamicFastBuffers::TypecodeAPI::createCharacter(),
		DynamicFastBuffers::TypecodeAPI::createShort(),
		NULL
	);
	
	size += DynamicFastBuffers::TypecodeAPI::checkSerializedDataSize(
		tc);
		
	char *buffer = (char*) malloc(size);
	eprosima::FastCdr *cdr;
	eprosima::FastBuffer *cdrBuffer;
	cdrBuffer = new eprosima::FastBuffer(buffer, size); 
	cdr = new eprosima::FastCdr(*cdrBuffer);

	DynamicFastBuffers::Bytecode *bytecodeSerialization = DynamicFastBuffers::BytecodeAPI::generateBytecode(tc, DynamicFastBuffers::SERIALIZE);
	DynamicFastBuffers::Bytecode *bytecodeDeserialization = DynamicFastBuffers::BytecodeAPI::generateBytecode(tc, DynamicFastBuffers::DESERIALIZE);

	try{
		cdr->reset();
		DynamicFastBuffers::SerializerAPI::serialize((void*) &inputStruct, bytecodeSerialization, cdr);
		return true;
	}catch(exception e){
		return false;
	}

}

bool serializeBlackBox03(eprosima::FastCdr *cdrp)
{
	outer inputStruct;
	inner in1;
	
	in1.att1 = 'A';
	in1.att2 = 'B';
	in1.att3 = 1000;

	inputStruct.att1 = 10;
	inputStruct.att2 = "OUTER";
	inputStruct.att3 = 20;
	inputStruct.att4 =  in1;
	
	int size = 0;
	
	

	DynamicFastBuffers::Typecode *typecode = DynamicFastBuffers::TypecodeAPI::createStruct(
		DynamicFastBuffers::TypecodeAPI::createFloat(),
		DynamicFastBuffers::TypecodeAPI::createString(),
		DynamicFastBuffers::TypecodeAPI::createInteger(),
		DynamicFastBuffers::TypecodeAPI::createStruct(
			DynamicFastBuffers::TypecodeAPI::createCharacter(),
			DynamicFastBuffers::TypecodeAPI::createCharacter(),
			DynamicFastBuffers::TypecodeAPI::createShort(),
			NULL
		),
		NULL
	);
	
	size += DynamicFastBuffers::TypecodeAPI::checkSerializedDataSize(
		typecode);
		
	char *buffer = (char*) malloc(size);
	eprosima::FastCdr *cdr;
	eprosima::FastBuffer *cdrBuffer;
	cdrBuffer = new eprosima::FastBuffer(buffer, size); 
	cdr = new eprosima::FastCdr(*cdrBuffer);

	DynamicFastBuffers::Bytecode *bytecodeSerialization = DynamicFastBuffers::BytecodeAPI::generateBytecode(typecode, DynamicFastBuffers::SERIALIZE);
	DynamicFastBuffers::Bytecode *bytecodeDeserialization = DynamicFastBuffers::BytecodeAPI::generateBytecode(typecode, DynamicFastBuffers::DESERIALIZE);

	try{
		cdr->reset();
		DynamicFastBuffers::SerializerAPI::serialize((void*) &inputStruct, bytecodeSerialization, cdr);
		return true;
	}catch(exception e){
		return false;
	}
}

bool deserializeBlackBox01(eprosima::FastCdr *cdrp)
{
	DynamicFastBuffers::Bytecode *bc1;
	DynamicFastBuffers::Bytecode *bc2;
	DynamicFastBuffers::Bytecode *bc3;
	DynamicFastBuffers::Bytecode *bc4;
	DynamicFastBuffers::Bytecode *bc5;
	DynamicFastBuffers::Bytecode *bc6;
	DynamicFastBuffers::Bytecode *bc7;
	DynamicFastBuffers::Bytecode *bc8;
	
	int size = 0;
	
	size += DynamicFastBuffers::TypecodeAPI::checkSerializedDataSize(
		DynamicFastBuffers::TypecodeAPI::createInteger());
	size += DynamicFastBuffers::TypecodeAPI::checkSerializedDataSize(
		DynamicFastBuffers::TypecodeAPI::createShort());
	size += DynamicFastBuffers::TypecodeAPI::checkSerializedDataSize(
		DynamicFastBuffers::TypecodeAPI::createFloat());
	size += DynamicFastBuffers::TypecodeAPI::checkSerializedDataSize(
		DynamicFastBuffers::TypecodeAPI::createDouble());
	size += DynamicFastBuffers::TypecodeAPI::checkSerializedDataSize(
		DynamicFastBuffers::TypecodeAPI::createLong());
	size += DynamicFastBuffers::TypecodeAPI::checkSerializedDataSize(
		DynamicFastBuffers::TypecodeAPI::createString());
	size += DynamicFastBuffers::TypecodeAPI::checkSerializedDataSize(
		DynamicFastBuffers::TypecodeAPI::createCharacter());
	size += DynamicFastBuffers::TypecodeAPI::checkSerializedDataSize(
		DynamicFastBuffers::TypecodeAPI::createBoolean());
	
	char *buffer = (char*) malloc(size);
	eprosima::FastCdr *cdr;
	eprosima::FastBuffer *cdrBuffer;
	cdrBuffer = new eprosima::FastBuffer(buffer, size); 
	cdr = new eprosima::FastCdr(*cdrBuffer);

	bc1 = DynamicFastBuffers::BytecodeAPI::generateBytecode(DynamicFastBuffers::TypecodeAPI::createInteger(), DynamicFastBuffers::SERIALIZE);
	bc2 = DynamicFastBuffers::BytecodeAPI::generateBytecode(DynamicFastBuffers::TypecodeAPI::createShort(), DynamicFastBuffers::SERIALIZE);
	bc3 = DynamicFastBuffers::BytecodeAPI::generateBytecode(DynamicFastBuffers::TypecodeAPI::createFloat(), DynamicFastBuffers::SERIALIZE);
	bc4 = DynamicFastBuffers::BytecodeAPI::generateBytecode(DynamicFastBuffers::TypecodeAPI::createDouble(), DynamicFastBuffers::SERIALIZE);
	bc5 = DynamicFastBuffers::BytecodeAPI::generateBytecode(DynamicFastBuffers::TypecodeAPI::createLong(), DynamicFastBuffers::SERIALIZE);
	bc6 = DynamicFastBuffers::BytecodeAPI::generateBytecode(DynamicFastBuffers::TypecodeAPI::createString(), DynamicFastBuffers::SERIALIZE);
	bc7 = DynamicFastBuffers::BytecodeAPI::generateBytecode(DynamicFastBuffers::TypecodeAPI::createCharacter(), DynamicFastBuffers::SERIALIZE);
	bc8 = DynamicFastBuffers::BytecodeAPI::generateBytecode(DynamicFastBuffers::TypecodeAPI::createBoolean(), DynamicFastBuffers::SERIALIZE);
	
	
	
	cdr->reset();

	int32_t i1 = 10, i2 = 0;
	DynamicFastBuffers::SerializerAPI::serialize((void*) &i1, bc1, cdr); 
	short s1 = 3, s2 = 0;
	DynamicFastBuffers::SerializerAPI::serialize((void*) &s1, bc2, cdr); 
	float f1 = 5, f2 = 0;
	DynamicFastBuffers::SerializerAPI::serialize((void*) &f1, bc3, cdr); 
	double d1 = 3.5, d2 = 0;
	DynamicFastBuffers::SerializerAPI::serialize((void*) &d1, bc4, cdr); 
	int64_t l1 = 22, l2 = 0;
	DynamicFastBuffers::SerializerAPI::serialize((void*) &l1, bc5, cdr); 
	string str1 = "HELLO WORLD";
	string str2 = "";
	DynamicFastBuffers::SerializerAPI::serialize((void*) &str1, bc6, cdr); 
	char c1 = 'A', c2 = 0;
	DynamicFastBuffers::SerializerAPI::serialize((void*) &c1, bc7, cdr); 
	bool b1 = false, b2 = true;
	DynamicFastBuffers::SerializerAPI::serialize((void*) &b1, bc8, cdr);
	
	bc1 = DynamicFastBuffers::BytecodeAPI::generateBytecode(DynamicFastBuffers::TypecodeAPI::createInteger(), DynamicFastBuffers::DESERIALIZE);
	bc2 = DynamicFastBuffers::BytecodeAPI::generateBytecode(DynamicFastBuffers::TypecodeAPI::createShort(), DynamicFastBuffers::DESERIALIZE);
	bc3 = DynamicFastBuffers::BytecodeAPI::generateBytecode(DynamicFastBuffers::TypecodeAPI::createFloat(), DynamicFastBuffers::DESERIALIZE);
	bc4 = DynamicFastBuffers::BytecodeAPI::generateBytecode(DynamicFastBuffers::TypecodeAPI::createDouble(), DynamicFastBuffers::DESERIALIZE);
	bc5 = DynamicFastBuffers::BytecodeAPI::generateBytecode(DynamicFastBuffers::TypecodeAPI::createLong(), DynamicFastBuffers::DESERIALIZE);
	bc6 = DynamicFastBuffers::BytecodeAPI::generateBytecode(DynamicFastBuffers::TypecodeAPI::createString(), DynamicFastBuffers::DESERIALIZE);
	bc7 = DynamicFastBuffers::BytecodeAPI::generateBytecode(DynamicFastBuffers::TypecodeAPI::createCharacter(), DynamicFastBuffers::DESERIALIZE);
	bc8 = DynamicFastBuffers::BytecodeAPI::generateBytecode(DynamicFastBuffers::TypecodeAPI::createBoolean(), DynamicFastBuffers::DESERIALIZE);
	
	cdr->reset();
	
	DynamicFastBuffers::SerializerAPI::deserialize((void*) &i2, bc1, cdr);
	DynamicFastBuffers::SerializerAPI::deserialize((void*) &s2, bc2, cdr); 
	DynamicFastBuffers::SerializerAPI::deserialize((void*) &f2, bc3, cdr); 
	DynamicFastBuffers::SerializerAPI::deserialize((void*) &d2, bc4, cdr); 
	DynamicFastBuffers::SerializerAPI::deserialize((void*) &l2, bc5, cdr); 
	DynamicFastBuffers::SerializerAPI::deserialize((void*) &str2, bc6, cdr); 
	DynamicFastBuffers::SerializerAPI::deserialize((void*) &c2, bc7, cdr); 
	DynamicFastBuffers::SerializerAPI::deserialize((void*) &b2, bc8, cdr); 
	
	//
	// Comparison
	//
	bool returnValue = true;
	returnValue &= (i1 == i2);
	returnValue &= (s1 == s2);
	returnValue &= (f1 == f2);
	returnValue &= (d1 == d2);
	returnValue &= (l1 == l2);
	returnValue &= (str1 == str2);
	returnValue &= (c1 == c2);
	returnValue &= (b1 == b2);
	
	return returnValue;
}

bool deserializeBlackBox02(eprosima::FastCdr *cdrp)
{
	inner inputStruct, outputStruct;
	
	inputStruct.att1 = 'A';
	inputStruct.att2 = 'B';
	inputStruct.att3 = 1000;
	
	int size = 0;
	
	DynamicFastBuffers::Typecode *tc = DynamicFastBuffers::TypecodeAPI::createStruct(
		DynamicFastBuffers::TypecodeAPI::createCharacter(),
		DynamicFastBuffers::TypecodeAPI::createCharacter(),
		DynamicFastBuffers::TypecodeAPI::createShort(),
		NULL
	);
	
	size += DynamicFastBuffers::TypecodeAPI::checkSerializedDataSize(
		DynamicFastBuffers::TypecodeAPI::createInteger());
		
	char *buffer = (char*) malloc(size);
	eprosima::FastCdr *cdr;
	eprosima::FastBuffer *cdrBuffer;
	cdrBuffer = new eprosima::FastBuffer(buffer, size); 
	cdr = new eprosima::FastCdr(*cdrBuffer);

	DynamicFastBuffers::Bytecode *bytecodeSerialization = DynamicFastBuffers::BytecodeAPI::generateBytecode(tc, DynamicFastBuffers::SERIALIZE);
	DynamicFastBuffers::Bytecode *bytecodeDeserialization = DynamicFastBuffers::BytecodeAPI::generateBytecode(tc, DynamicFastBuffers::DESERIALIZE);

	cdr->reset();
	DynamicFastBuffers::SerializerAPI::serialize((void*) &inputStruct, bytecodeSerialization, cdr);

	cdr->reset();

	DynamicFastBuffers::SerializerAPI::deserialize((void*) &outputStruct, bytecodeDeserialization, cdr);

	bool returnValue = true;
	returnValue &= (inputStruct.att1 == outputStruct.att1);
	returnValue &= (inputStruct.att2 == outputStruct.att2);
	returnValue &= (inputStruct.att3 == outputStruct.att3);
	
	return returnValue;
}

bool deserializeBlackBox03(eprosima::FastCdr *cdrp)
{
	outer inputStruct, outputStruct; 
	inner in1;
	
	int size = 0;
	
	
	
	in1.att1 = 'A';
	in1.att2 = 'B';
	in1.att3 = 1000;

	inputStruct.att1 = 10;
	inputStruct.att2 = "OUTER";
	inputStruct.att3 = 20;
	inputStruct.att4 =  in1;
	
	DynamicFastBuffers::Typecode *typecode = DynamicFastBuffers::TypecodeAPI::createStruct(
		DynamicFastBuffers::TypecodeAPI::createFloat(),
		DynamicFastBuffers::TypecodeAPI::createString(),
		DynamicFastBuffers::TypecodeAPI::createInteger(),
		DynamicFastBuffers::TypecodeAPI::createStruct(
			DynamicFastBuffers::TypecodeAPI::createCharacter(),
			DynamicFastBuffers::TypecodeAPI::createCharacter(),
			DynamicFastBuffers::TypecodeAPI::createShort(),
			NULL
		),
		NULL
	);
	
	size += DynamicFastBuffers::TypecodeAPI::checkSerializedDataSize(
		typecode);
		
	char *buffer = (char*) malloc(size);
	eprosima::FastCdr *cdr;
	eprosima::FastBuffer *cdrBuffer;
	cdrBuffer = new eprosima::FastBuffer(buffer, size); 
	cdr = new eprosima::FastCdr(*cdrBuffer);
	
	
	DynamicFastBuffers::Bytecode *bytecodeSerialization = DynamicFastBuffers::BytecodeAPI::generateBytecode(typecode, DynamicFastBuffers::SERIALIZE);
	DynamicFastBuffers::Bytecode *bytecodeDeserialization = DynamicFastBuffers::BytecodeAPI::generateBytecode(typecode, DynamicFastBuffers::DESERIALIZE);

	cdr->reset();
	
	DynamicFastBuffers::SerializerAPI::serialize((void*) &inputStruct, bytecodeSerialization, cdr);
		
	cdr->reset();

	DynamicFastBuffers::SerializerAPI::deserialize((void*) &outputStruct, bytecodeDeserialization, cdr);
	
	bool returnValue = true;
	
	returnValue &= (inputStruct.att1 == outputStruct.att1);
	returnValue &= (inputStruct.att2 == outputStruct.att2);
	returnValue &= (inputStruct.att3 == outputStruct.att3);
	returnValue &= (inputStruct.att4.att1 == outputStruct.att4.att1);
	returnValue &= (inputStruct.att4.att2 == outputStruct.att4.att2);
	returnValue &= (inputStruct.att4.att3 == outputStruct.att4.att3);
	
	return returnValue;
}

struct innerBlackBox03
{
	int32_t att1;
	int64_t att2;
	float att3;
};

struct outerBlackBox04
{
	innerBlackBox03 innerbb;
	std::string att2;
	bool att3;
};

bool deserializeBlackBox04(eprosima::FastCdr *cdrp)
{

	outerBlackBox04 inputStruct, outputStruct; 
	innerBlackBox03 in1;
	
	in1.att1 = 5;
	in1.att2 = 7;
	in1.att3 = 9.0;

	inputStruct.innerbb = in1;
	inputStruct.att2 = "OUTER";
	inputStruct.att3 = true;
	
	DynamicFastBuffers::Typecode *typecode = DynamicFastBuffers::TypecodeAPI::createStruct(
		DynamicFastBuffers::TypecodeAPI::createStruct(
			DynamicFastBuffers::TypecodeAPI::createInteger(),
			DynamicFastBuffers::TypecodeAPI::createLong(),
			DynamicFastBuffers::TypecodeAPI::createFloat(),
			NULL
		),
		DynamicFastBuffers::TypecodeAPI::createString(),
		DynamicFastBuffers::TypecodeAPI::createBoolean(),
		NULL
	);
	
	char *buffer = (char*) malloc(500);
	eprosima::FastCdr *cdr;
	eprosima::FastBuffer *cdrBuffer;
	cdrBuffer = new eprosima::FastBuffer(buffer, 500); 
	cdr = new eprosima::FastCdr(*cdrBuffer);
	
	
	DynamicFastBuffers::Bytecode *bytecodeSerialization = DynamicFastBuffers::BytecodeAPI::generateBytecode(typecode, DynamicFastBuffers::SERIALIZE);
	DynamicFastBuffers::Bytecode *bytecodeDeserialization = DynamicFastBuffers::BytecodeAPI::generateBytecode(typecode, DynamicFastBuffers::DESERIALIZE);

	cdr->reset();
	
	DynamicFastBuffers::SerializerAPI::serialize((void*) &inputStruct, bytecodeSerialization, cdr);
		
	cdr->reset();

	DynamicFastBuffers::SerializerAPI::deserialize((void*) &outputStruct, bytecodeDeserialization, cdr);
	
	bool returnValue = true;
	
	returnValue &= (inputStruct.innerbb.att1 == outputStruct.innerbb.att1);
	returnValue &= (inputStruct.innerbb.att2 == outputStruct.innerbb.att2);
	returnValue &= (inputStruct.innerbb.att3 == outputStruct.innerbb.att3);
	returnValue &= (inputStruct.att2 == outputStruct.att2);
	returnValue &= (inputStruct.att3 == outputStruct.att3);
	
	return returnValue;
}

struct outerBlackBox05
{
	innerBlackBox03 innerbb1;
	std::string att2;
	bool att3;
	innerBlackBox03 innerbb2;
};

bool deserializeBlackBox05()
{
	outerBlackBox05 inputStruct, outputStruct; 
	innerBlackBox03 in1;
	
	in1.att1 = 5;
	in1.att2 = 7;
	in1.att3 = 9.0;

	inputStruct.innerbb1 = in1;
	inputStruct.att2 = "OUTER";
	inputStruct.att3 = true;
	inputStruct.innerbb2 = in1;
	
	DynamicFastBuffers::Typecode *typecode = DynamicFastBuffers::TypecodeAPI::createStruct(
		DynamicFastBuffers::TypecodeAPI::createStruct(
			DynamicFastBuffers::TypecodeAPI::createInteger(),
			DynamicFastBuffers::TypecodeAPI::createLong(),
			DynamicFastBuffers::TypecodeAPI::createFloat(),
			NULL
		),
		DynamicFastBuffers::TypecodeAPI::createString(),
		DynamicFastBuffers::TypecodeAPI::createBoolean(),
		DynamicFastBuffers::TypecodeAPI::createStruct(
			DynamicFastBuffers::TypecodeAPI::createInteger(),
			DynamicFastBuffers::TypecodeAPI::createLong(),
			DynamicFastBuffers::TypecodeAPI::createFloat(),
			NULL
		),
		NULL
	);
	
	char *buffer = (char*) malloc(500);
	eprosima::FastCdr *cdr;
	eprosima::FastBuffer *cdrBuffer;
	cdrBuffer = new eprosima::FastBuffer(buffer, 500); 
	cdr = new eprosima::FastCdr(*cdrBuffer);
	
	
	DynamicFastBuffers::Bytecode *bytecodeSerialization = DynamicFastBuffers::BytecodeAPI::generateBytecode(typecode, DynamicFastBuffers::SERIALIZE);
	DynamicFastBuffers::Bytecode *bytecodeDeserialization = DynamicFastBuffers::BytecodeAPI::generateBytecode(typecode, DynamicFastBuffers::DESERIALIZE);

	cdr->reset();
	
	DynamicFastBuffers::SerializerAPI::serialize((void*) &inputStruct, bytecodeSerialization, cdr);
		
	cdr->reset();

	DynamicFastBuffers::SerializerAPI::deserialize((void*) &outputStruct, bytecodeDeserialization, cdr);
	
	bool returnValue = true;
	
	returnValue &= (inputStruct.innerbb1.att1 == outputStruct.innerbb1.att1);
	returnValue &= (inputStruct.innerbb1.att2 == outputStruct.innerbb1.att2);
	returnValue &= (inputStruct.innerbb1.att3 == outputStruct.innerbb1.att3);
	returnValue &= (inputStruct.att2 == outputStruct.att2);
	returnValue &= (inputStruct.att3 == outputStruct.att3);
	returnValue &= (inputStruct.innerbb2.att1 == outputStruct.innerbb2.att1);
	returnValue &= (inputStruct.innerbb2.att2 == outputStruct.innerbb2.att2);
	returnValue &= (inputStruct.innerbb2.att3 == outputStruct.innerbb2.att3);
	
	return returnValue;
}

bool addMemberBlackBox01()
{
	DynamicFastBuffers::Typecode *tcInteger;
	DynamicFastBuffers::Typecode *tcStruct;
	tcInteger = DynamicFastBuffers::TypecodeAPI::createInteger();
	tcStruct = DynamicFastBuffers::TypecodeAPI::createStruct(NULL);

	DynamicFastBuffers::TypecodeAPI::addMembers(tcStruct, tcInteger, NULL);

	//
	// Comparison
	//
	bool returnValue = true;
	returnValue &= (tcStruct->getMembers()[0].getKind() == DynamicFastBuffers::TC_INTEGER);
	
	return returnValue;
}

bool addMemberBlackBox02()
{
	DynamicFastBuffers::Typecode *structure = DynamicFastBuffers::TypecodeAPI::createStruct(NULL);
	DynamicFastBuffers::TypecodeAPI::addMembers(structure, DynamicFastBuffers::TypecodeAPI::createDouble(), NULL);

	DynamicFastBuffers::Typecode *outerStruct;
	outerStruct = DynamicFastBuffers::TypecodeAPI::createStruct(structure, NULL);

	//
	// Comparison
	//
	bool returnValue = true;
	returnValue &= (outerStruct->getKind() == DynamicFastBuffers::TC_STRUCT);
	returnValue &= (outerStruct->getMembers()[0].getKind() == DynamicFastBuffers::TC_STRUCT);
	
	return returnValue;
}

bool addMemberBlackBox03()
{
	DynamicFastBuffers::Typecode *structure = DynamicFastBuffers::TypecodeAPI::createStruct(NULL);
	DynamicFastBuffers::TypecodeAPI::addMembers(structure, DynamicFastBuffers::TypecodeAPI::createBoolean(), DynamicFastBuffers::TypecodeAPI::createDouble(), NULL);

	//
	// Comparison
	//
	bool returnValue = true;
	returnValue &= (structure->getKind() == DynamicFastBuffers::TC_STRUCT);
	returnValue &= (structure->getMembers()[0].getKind() == DynamicFastBuffers::TC_BOOLEAN);
	returnValue &= (structure->getMembers()[1].getKind() == DynamicFastBuffers::TC_DOUBLE);
	
	return returnValue;
}

bool addMemberBlackBox04()
{
	DynamicFastBuffers::Typecode *structure1 = DynamicFastBuffers::TypecodeAPI::createStruct(NULL);
	DynamicFastBuffers::TypecodeAPI::addMembers(
		structure1, 
		DynamicFastBuffers::TypecodeAPI::createFloat(), 
		DynamicFastBuffers::TypecodeAPI::createArray(DynamicFastBuffers::TypecodeAPI::createShort(), 1, 5, 0),
		NULL
	);
	DynamicFastBuffers::Typecode *structure2 = DynamicFastBuffers::TypecodeAPI::createStruct(NULL);
	DynamicFastBuffers::TypecodeAPI::addMembers(
		structure2, 
		DynamicFastBuffers::TypecodeAPI::createBoolean(), 
		DynamicFastBuffers::TypecodeAPI::createDouble(),
		NULL
	);
	
	DynamicFastBuffers::Typecode *outerStruct;
	outerStruct = DynamicFastBuffers::TypecodeAPI::createStruct(structure1, structure2, NULL);

	//
	// Comparison
	//
	bool returnValue = true;
	returnValue &= (outerStruct->getKind() == DynamicFastBuffers::TC_STRUCT);
	returnValue &= (outerStruct->getMembers()[0].getKind() == DynamicFastBuffers::TC_STRUCT);
	returnValue &= (outerStruct->getMembers()[1].getKind() == DynamicFastBuffers::TC_STRUCT);
	
	return returnValue;
}

void setUp(eprosima::FastCdr *&cdr, eprosima::FastBuffer *&fastBuffer, char* buffer)
{
	fastBuffer = new eprosima::FastBuffer(buffer, 500); 
	cdr = new eprosima::FastCdr(*fastBuffer);
}

void tearDown(eprosima::FastCdr *&cdr, eprosima::FastBuffer *&fastBuffer)
{
	delete cdr;
	delete fastBuffer;
}

int main()
{
	char buffer[500];
	eprosima::FastCdr *cdr;
	eprosima::FastBuffer *cdrBuffer;
	setUp(cdr, cdrBuffer, buffer);

	cout << "UNIT TESTS:\n\n";

	if(generateBytecodeWhiteBox02()){
		cout << "TEST: generateBytecodeWhiteBox02 ended succesfully.\nData Comparison: CORRECT" << endl;
	}else{
		cout << "TEST: generateBytecodeWhiteBox02 failed.\nData Comparison: FAIL" << endl;
		return -1;
	}

	if(addMembersWhiteBox01()){
		cout << "TEST: addMembersWhiteBox01 ended succesfully.\nData Comparison: CORRECT" << endl;
	}else{
		cout << "TEST: addMembersWhiteBox01 failed.\nData Comparison: FAIL" << endl;
		return -1;
	}

	if (addMembersWhiteBox02()){
		cout << "TEST: addMembersWhiteBox02 ended succesfully.\nData Comparison: CORRECT" << endl;
	}else{
		cout << "TEST: addMembersWhiteBox02 failed.\nData Comparison: FAIL" << endl;
		return -1;
	}

	if(addMembersWhiteBox03()){
		cout << "TEST: addMembersWhiteBox03 ended succesfully.\nData Comparison: CORRECT" << endl;
	}else{
		cout << "TEST: addMembersWhiteBox03 failed.\nData Comparison: FAIL" << endl;
		return -1;
	}

	if(addMembersWhiteBox04()){
		cout << "TEST: addMembersWhiteBox04 ended succesfully.\nData Comparison: CORRECT" << endl;
	}else{
		cout << "TEST: addMembersWhiteBox04 failed.\nData Comparison: FAIL" << endl;
		return -1;
	}

	if(addMembersWhiteBox05()){
		cout << "TEST: addMembersWhiteBox05 ended succesfully.\nData Comparison: CORRECT" << endl;
	}else{
		cout << "TEST: addMembersWhiteBox05 failed.\nData Comparison: FAIL" << endl;
		return -1;
	}

	if(createTypeBlackBox()){
		cout << "TEST: createTypeBlackBox ended succesfully.\nData Comparison: CORRECT" << endl;
	}else{
		cout << "TEST: createTypeBlackBox failed.\nData Comparison: FAIL" << endl;
		return -1;
	}

	if(addMembersBlackBox01()){
		cout << "TEST: addMembersBlackBox01 ended succesfully.\nData Comparison: CORRECT" << endl;
	}else{
		cout << "TEST: addMembersBlackBox01 failed.\nData Comparison: FAIL" << endl;
		return -1;
	}

	if(addMembersBlackBox02()){
		cout << "TEST: addMembersBlackBox02 ended succesfully.\nData Comparison: CORRECT" << endl;
	}else{
		cout << "TEST: addMembersBlackBox02 failed.\nData Comparison: FAIL" << endl;
		return -1;
	}

	if(addMembersBlackBox03()){
		cout << "TEST: addMembersBlackBox03 ended succesfully.\nData Comparison: CORRECT" << endl;
	}else{
		cout << "TEST: addMembersBlackBox03 failed.\nData Comparison: FAIL" << endl;
		return -1;
	}

	if(addMembersBlackBox04()){
		cout << "TEST: addMembersBlackBox04 ended succesfully.\nData Comparison: CORRECT" << endl;
	}else{
		cout << "TEST: addMembersBlackBox04 failed.\nData Comparison: FAIL" << endl;
		return -1;
	}

	if(generateBytecodeBlakBox01()){
		cout << "TEST: generateBytecodeBlakBox01 ended succesfully.\nData Comparison: CORRECT" << endl;
	}else{
		cout << "TEST: generateBytecodeBlakBox01 failed.\nData Comparison: FAIL" << endl;
		return -1;
	}
	
	if(generateBytecodeBlakBox02()){
		cout << "TEST: generateBytecodeBlakBox02 ended succesfully.\nData Comparison: CORRECT" << endl;
	}else{
		cout << "TEST: generateBytecodeBlakBox02 failed.\nData Comparison: FAIL" << endl;
		return -1;
	}

	if(serializeBlackBox01(cdr)){
		cout << "TEST: serializeBlackBox01 ended succesfully.\nData Comparison: CORRECT" << endl;
	}else{
		cout << "TEST: serializeBlackBox01 failed.\nData Comparison: FAIL" << endl;
		return -1;
	}

	if (serializeBlackBox02(cdr)){
		cout << "TEST: serializeBlackBox02 ended succesfully.\nData Comparison: CORRECT" << endl;
	}else{
		cout << "TEST: serializeBlackBox02 failed.\nData Comparison: FAIL" << endl;
		return -1;
	}

	if (serializeBlackBox03(cdr)){
		cout << "TEST: serializeBlackBox03 ended succesfully.\nData Comparison: CORRECT" << endl;
	}else{
		cout << "TEST: serializeBlackBox03 failed.\nData Comparison: FAIL" << endl;
		return -1;
	}

	if(deserializeBlackBox01(cdr)){
		cout << "TEST: deserializeBlackBox01 ended succesfully.\nData Comparison: CORRECT" << endl;
	}else{
		cout << "TEST: deserializeBlackBox01 failed.\nData Comparison: FAIL" << endl;
		return -1;
	}

	if(deserializeBlackBox02(cdr)){
		cout << "TEST: deserializeBlackBox02 ended succesfully.\nData Comparison: CORRECT" << endl;
	}else{
		cout << "TEST: deserializeBlackBox02 failed.\nData Comparison: FAIL" << endl;
		return -1;
	}

	if(deserializeBlackBox03(cdr)){
		cout << "TEST: deserializeBlackBox03 ended succesfully.\nData Comparison: CORRECT" << endl;
	}else{
		cout << "TEST: deserializeBlackBox03 failed.\nData Comparison: FAIL" << endl;
		return -1;
	}

	if(deserializeBlackBox04(cdr)){
		cout << "TEST: deserializeBlackBox04 ended succesfully.\nData Comparison: CORRECT" << endl;
	}else{
		cout << "TEST: deserializeBlackBox04 failed.\nData Comparison: FAIL" << endl;
		return -1;
	}

	if(deserializeBlackBox05()){
		cout << "TEST: deserializeBlackBox05 ended succesfully.\nData Comparison: CORRECT" << endl;
	}else{
		cout << "TEST: deserializeBlackBox05 failed.\nData Comparison: FAIL" << endl;
		return -1;
	}

	if(addMemberBlackBox01()){
		cout << "TEST: addMemberBlackBox01 ended succesfully.\nData Comparison: CORRECT" << endl;
	}else{
		cout << "TEST: addMemberBlackBox01 failed.\nData Comparison: FAIL" << endl;
		return -1;
	}

	if(addMemberBlackBox02()){
		cout << "TEST: addMemberBlackBox02 ended succesfully.\nData Comparison: CORRECT" << endl;
	}else{
		cout << "TEST: addMemberBlackBox02 failed.\nData Comparison: FAIL" << endl;
		return -1;
	}

	if(addMemberBlackBox03()){
		cout << "TEST: addMemberBlackBox03 ended succesfully.\nData Comparison: CORRECT" << endl;
	}else{
		cout << "TEST: addMemberBlackBox03 failed.\nData Comparison: FAIL" << endl;
		return -1;
	}

	if(addMemberBlackBox04()){
		cout << "TEST: addMemberBlackBox04 ended succesfully.\nData Comparison: CORRECT" << endl;
	}else{
		cout << "TEST: addMemberBlackBox04 failed.\nData Comparison: FAIL" << endl;
		return -1;
	}





	tearDown(cdr, cdrBuffer);
	return 0;
}

