#include "simulation/Elements.h"
//#TPT-Directive ElementClass Element_PLST PT_PLST 182
Element_PLST::Element_PLST()
{
	Identifier = "DEFAULT_PT_PLST";
	Name = "PLST";
	Colour = PIXPACK(0x00AA9C);
	MenuVisible = 1;
	MenuSection = SC_SOLIDS;
	Enabled = 1;
	
	Advection = 0.0f;
	AirDrag = 0.00f * CFDS;
	AirLoss = 0.97f;
	Loss = 0.50f;
	Collision = 0.0f;
	Gravity = 0.0f;
	Diffusion = 0.00f;
	HotAir = 0.000f	* CFDS;
	Falldown = 0;
	
	Flammable = 0;
	Explosive = 0;
	Meltable = 0;
	Hardness = 2;
	
	Weight = 100;
	
	Temperature = R_TEMP+0.0f	+273.15f;
	HeatConduct = 75;
	Description = "Plastic. Made from OIL, deforms under high pressure, melts at moderate temperatures. Slightly flammable.";
	
	State = ST_SOLID;
	Properties = TYPE_SOLID|PROP_LIFE_DEC;
	
	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = R_TEMP+220.0f +273.15f;
	HighTemperatureTransition = PT_LPLS;
	
	Update = &Element_PLST::update;
	
}

//#TPT-Directive ElementHeader Element_PLST static int update(UPDATE_FUNC_ARGS)
int Element_PLST::update(UPDATE_FUNC_ARGS)
 {
	if (!parts[i].life && sim->pv[y/CELL][x/CELL]>7.0f)
		parts[i].life = rand()%80;
	if (parts[i].life)
	{
		float advection = 0.1f;
		parts[i].vx += advection*sim->vx[y/CELL][x/CELL];
		parts[i].vy += advection*sim->vy[y/CELL][x/CELL];
	}

	return 0;
}


Element_PLST::~Element_PLST() {}
