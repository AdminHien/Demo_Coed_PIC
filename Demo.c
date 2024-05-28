
/************************************************************************************
 * Include file
 ************************************************************************************/
#include "sim_hal.h"

/************************************************************************************
 * Function
 ************************************************************************************/
sim_state SIM_EnablePortClock(sim_port Port)
{
    sim_state Status = SIM_OK;
    /* Define the corresponding SIM_SCGC5 values for each PORT */
    const uint32_t SCGC5_Values[] =
    {
        [SIM_PORTA] = SIM_SCGC5_PORTA(1),
        [SIM_PORTB] = SIM_SCGC5_PORTB(1),
        [SIM_PORTC] = SIM_SCGC5_PORTC(1),
        [SIM_PORTD] = SIM_SCGC5_PORTD(1),
        [SIM_PORTE] = SIM_SCGC5_PORTE(1),

    };

    /* Check if Port is a valid PORT */
    if ((Port >= SIM_PORTA && Port <= SIM_PORTE))
    {
        /* Enable clock gate for the specified PORT */
        SIM_SCGC5 |= SCGC5_Values[Port];

    }
    else
    {
        /* Set Port to SIM_INVALID for invalid PORT */
        Status = SIM_ERROR;
    }

    return Status;
}

sim_state SIM_EnableClock_ADC0(sim_port Port)
{
	sim_state Status = SIM_OK;
	if((Port >= SIM_PORTB && Port <= SIM_PORTE))
	{
		SIM->SCGC6 |= SIM_SCGC6_ADC0_MASK;
	}
	else
	{
		 Status = SIM_ERROR;
	}
	return Status;
}

sim_state SIM_EnableClock_UART0(sim_port Port)
{
	sim_state Status = SIM_OK;
	if(Port == SIM_PORTA )
	{
		/*set UART0_Clock = MCGIRCLK*/

		/* Enable clock for UART0 */
		SIM->SCGC4 |= SIM_SCGC4_UART0_MASK;
		SIM->SOPT2 |= SIM_SOPT2_UART0SRC(1); // Use FLL clock for UART0
	}
	else
	{
		 Status = SIM_ERROR;
	}
	return Status;
}


/* End of file */
