/*
 * movement.h
 *
 *  Created on: Aug 18, 2014
 *      Author: Jakub Trzyna
 */

#ifndef MOVEMENT_H_
#define MOVEMENT_H_


void basePosition(int Speed)
{
	Speed = 13;

	char Leg=0;

	for(Leg=0b00000001; Leg<=0b00100000; Leg*=2)
	{
		if( (legLift(Leg, 0, MAX_SPEED) != DONE) || (legTurn(Leg, 0, MAX_SPEED, 0, 1) != DONE) )
		{
			while( legLift(Leg, 35, Speed) != DONE );
			while( legTurn(Leg, 0, Speed, 0, 1) != DONE );
			while( legLift(Leg, 0, Speed) != DONE );
		}
	}
}

void curveAdjust(int *Curve) // 0 to 28
{
	*Curve -= 14;

	switch(*Curve)
	{
	case -14: {
		*Curve = -56;
		break;
	}
	case -13: {
		*Curve = -28;
		break;
	}
	case -12: {
		*Curve = -28;
		break;
	}
	case -11: {
		*Curve = -15;
		break;
	}
	case -10: {
		*Curve = -13;
		break;
	}
	case -9: {
		*Curve = -11;
		break;
	}
	case -8: {
		*Curve = -9;
		break;
	}
	case -7: {
		*Curve = -7;
		break;
	}
	case -6: {
		*Curve = -6;
		break;
	}
	case -5: {
		*Curve = -5;
		break;
	}
	case -4: {
		*Curve = -4;
		break;
	}
	case -3: {
		*Curve = -3;
		break;
	}
	case -2: {
		*Curve = -2;
		break;
	}
	case -1: {
		*Curve = -1;
		break;
	}
	case 0: {
		*Curve = 0;
		break;
	}
	case 1: {
		*Curve = 1;
		break;
	}
	case 2: {
		*Curve = 2;
		break;
	}
	case 3: {
		*Curve = 3;
		break;
	}
	case 4: {
		*Curve = 4;
		break;
	}
	case 5: {
		*Curve = 5;
		break;
	}
	case 6: {
		*Curve = 6;
		break;
	}
	case 7: {
		*Curve = 7;
		break;
	}
	case 8: {
		*Curve = 9;
		break;
	}
	case 9: {
		*Curve = 11;
		break;
	}
	case 10: {
		*Curve = 13;
		break;
	}
	case 11: {
		*Curve = 15;
		break;
	}
	case 12: {
		*Curve = 28;
		break;
	}
	case 13: {
		*Curve = 28;
		break;
	}
	case 14: {
		*Curve = 56;
		break;
	}
	default: {
		*Curve = 0;
		break;
	}
	}
}

void go(int Speed, int Curve, int Direction)
{
	if(Speed>14) Speed = 14;

	if( (Step < 11) || (Step > 16) ) //it means that different action was previously done
		Step = 11;


	if(Step == 11)
		if( legLift(0b101010, 25, Speed) == DONE )
			Step = 12;

	if((Step == 12) && (Direction == 1) )
		if( legTurn(0b111111, -28, Speed, Curve, Direction) == DONE )
			Step = 13;
	if((Step == 12) && (Direction == 2) )
		if( legTurn(0b111111, 28, Speed, Curve, Direction) == DONE )
			Step = 13;

	if(Step == 13)
		if( legLift(0b101010, 0, Speed) == DONE )
			Step = 14;


	if(Step == 14)
		if(	legLift(0b010101, 25, Speed) == DONE )
			Step = 15;

	if( (Step == 15) && (Direction == 1) )
		if(	legTurn(0b111111, 28, Speed, Curve, Direction) == DONE )
			Step = 16;
	if( (Step == 15) && (Direction == 2) )
		if(	legTurn(0b111111, -28, Speed, Curve, Direction) == DONE )
			Step = 16;

	if(Step == 16)
		if( legLift(0b010101, 0, Speed) == DONE )
			Step = 11;
}

#endif /* MOVEMENT_H_ */
