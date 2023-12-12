#include "DSP281x_Device.h"
#include "DSP281x_GlobalPrototypes.h"
#include "rtwtypes.h"
#include "test.h"

void disableWatchdog(void)
{
  int *WatchdogWDCR = (void *) 0x7029;
  asm(" EALLOW ");
  *WatchdogWDCR = 0x0068;
  asm(" EDIS ");
}

void enable_interrupts()
{
  /* Enable global Interrupts and higher priority real-time debug events:*/
  EINT;                                /* Enable Global interrupt INTM*/
  ERTM;                                /* Enable Global realtime interrupt DBGM*/
}

void init_board ()
{
  /* Disable the watchdog        */
  DisableDog();

  /* Initialize the PLL control: PLLCR
   * DSP28_PLLCR is calculted from the crystal frequency use input
   */
  InitPll(10);

  /* Initialize the peripheral clocks*/
  InitPeripheralClocks();
  EALLOW;

  /* Configure low speed peripheral clocks */
  SysCtrlRegs.LOSPCP.all = 2U;

  /* Configure high speed peripheral clocks */
  SysCtrlRegs.HISPCP.all = 1U;
  EDIS;

  /* Perform additional configuration of the XTINF for speed up */
  XintfRegs.XINTCNF2.bit.XTIMCLK = 0;  /* XTIMCLK=SYSCLKOUT/1*/
  XintfRegs.XINTCNF2.bit.CLKOFF = 0;   /* XCLKOUT is enabled*/
  XintfRegs.XINTCNF2.bit.CLKMODE = 0;  /* XCLKOUT = XTIMCLK*/

  /* Make sure write buffer is empty before configuring buffering depth*/
  while (XintfRegs.XINTCNF2.bit.WLEVEL != 0) ;/* poll the WLEVEL bit*/
  XintfRegs.XINTCNF2.bit.WRBUFF = 0;   /* No write buffering*/

  /* Example: Assume Zone 7 is slow, so add additional BCYC cycles whenever
   * switching from Zone 7 to another Zone.  This will help avoid bus contention.
   */
  XintfRegs.XBANK.bit.BCYC = 7;        /* Add 7 cycles*/
  XintfRegs.XBANK.bit.BANK = 7;        /* select zone 7*/

  /* Zone 0 Configuration */
  /*
     XintfRegs.XTIMING0.bit.X2TIMING = 0;   // Timing scale factor = 1
     XintfRegs.XTIMING0.bit.XSIZE = 3;      // Always write as 11b
     XintfRegs.XTIMING0.bit.READYMODE = 1;  // XREADY is asynchronous
     XintfRegs.XTIMING0.bit.USEREADY = 0;   // Disable XREADY
     XintfRegs.XTIMING0.bit.XRDLEAD = 1;    // Read lead time
     XintfRegs.XTIMING0.bit.XRDACTIVE = 2;  // Read active time
     XintfRegs.XTIMING0.bit.XRDTRAIL = 0;   // Read trail time
     XintfRegs.XTIMING0.bit.XWRLEAD = 1;    // Write lead time
     XintfRegs.XTIMING0.bit.XWRACTIVE = 2;  // Write active time
     XintfRegs.XTIMING0.bit.XWRTRAIL = 0;   // Write trail time
   */
  XintfRegs.XTIMING0.all = (XintfRegs.XTIMING0.all & ~0x43FFFF) | 0x39428;

  /* Zone 1 Configuration */
  /*
     XintfRegs.XTIMING1.bit.X2TIMING = 0;    // Timing scale factor = 1
     XintfRegs.XTIMING1.bit.XSIZE = 3;       // Always write as 11b
     XintfRegs.XTIMING1.bit.READYMODE = 1;   // XREADY is asynchronous
     XintfRegs.XTIMING1.bit.USEREADY = 0;    // Disable XREADY
     XintfRegs.XTIMING1.bit.XRDLEAD = 1;     // Read lead time
     XintfRegs.XTIMING1.bit.XRDACTIVE = 2;   // Read active time
     XintfRegs.XTIMING1.bit.XRDTRAIL = 0;    // Read trail time
     XintfRegs.XTIMING1.bit.XWRLEAD = 1;     // Write lead time
     XintfRegs.XTIMING1.bit.XWRACTIVE = 2;   // Write active time
     XintfRegs.XTIMING1.bit.XWRTRAIL = 0;    // Write trail time
   */
  XintfRegs.XTIMING1.all = (XintfRegs.XTIMING1.all & ~0x43FFFF) | 0x39428;

  /* Zone 2 Configuration */
  /*
     XintfRegs.XTIMING2.bit.X2TIMING = 0;    // Timing scale factor = 1
     XintfRegs.XTIMING2.bit.XSIZE = 3;       // Always write as 11b
     XintfRegs.XTIMING2.bit.READYMODE = 1;   // XREADY is asynchronous
     XintfRegs.XTIMING2.bit.USEREADY = 0;    // Disable XREADY
     XintfRegs.XTIMING2.bit.XRDLEAD = 1;     // Read lead time
     XintfRegs.XTIMING2.bit.XRDACTIVE = 2;   // Read active time
     XintfRegs.XTIMING2.bit.XRDTRAIL = 0;    // Read trail time
     XintfRegs.XTIMING2.bit.XWRLEAD = 1;     // Write lead time
     XintfRegs.XTIMING2.bit.XWRACTIVE = 2;   // Write active time
     XintfRegs.XTIMING2.bit.XWRTRAIL = 0;    // Write trail time
   */
  XintfRegs.XTIMING2.all = (XintfRegs.XTIMING2.all & ~0x43FFFF) | 0x39428;

  /* Zone 6 Configuration */
  /*
     XintfRegs.XTIMING6.bit.X2TIMING = 0;    // Timing scale factor = 1
     XintfRegs.XTIMING6.bit.XSIZE = 3;       // Always write as 11b
     XintfRegs.XTIMING6.bit.READYMODE = 1;   // XREADY is asynchronous
     XintfRegs.XTIMING6.bit.USEREADY = 0;    // Disable XREADY
     XintfRegs.XTIMING6.bit.XRDLEAD = 1;     // Read lead time
     XintfRegs.XTIMING6.bit.XRDACTIVE = 2;   // Read active time
     XintfRegs.XTIMING6.bit.XRDTRAIL = 0;    // Read trail time
     XintfRegs.XTIMING6.bit.XWRLEAD = 1;     // Write lead time
     XintfRegs.XTIMING6.bit.XWRACTIVE = 2;   // Write active time
     XintfRegs.XTIMING6.bit.XWRTRAIL = 0;    // Write trail time
   */
  XintfRegs.XTIMING6.all = (XintfRegs.XTIMING6.all & ~0x43FFFF) | 0x39428;

  /* Zone 7 Configuration */
  /*
     XintfRegs.XTIMING7.bit.X2TIMING = 0;    // Timing scale factor = 1
     XintfRegs.XTIMING7.bit.XSIZE = 3;       // Always write as 11b
     XintfRegs.XTIMING7.bit.READYMODE = 1;   // XREADY is asynchronous
     XintfRegs.XTIMING7.bit.USEREADY = 0;    // Disable XREADY
     XintfRegs.XTIMING7.bit.XRDLEAD = 1;     // Read lead time
     XintfRegs.XTIMING7.bit.XRDACTIVE = 2;   // Read active time
     XintfRegs.XTIMING7.bit.XRDTRAIL = 0;    // Read trail time
     XintfRegs.XTIMING7.bit.XWRLEAD = 1;     // Write lead time
     XintfRegs.XTIMING7.bit.XWRACTIVE = 2;   // Write active time
     XintfRegs.XTIMING7.bit.XWRTRAIL = 0;    // Write trail time
   */
  XintfRegs.XTIMING7.all = (XintfRegs.XTIMING7.all & ~0x43FFFF) | 0x39428;

  /* Flush pipeline to ensure that the write is complete. Wait to be sure. */
  asm(" RPT #6 || NOP");

  /* Disable and clear all CPU interrupts */
  DINT;
  IER = 0x0000;
  IFR = 0x0000;
  InitPieCtrl();
  InitPieVectTable();

  /* initial eCAN function.... */

  /* initial SPI function.... */

  /* initial SCI function.... */
  InitCpuTimers();

  /* Initialize GPIO input qualification sampling period */
  EALLOW;
  GpioMuxRegs.GPAQUAL.bit.QUALPRD = 0;
  GpioMuxRegs.GPBQUAL.bit.QUALPRD = 0;
  GpioMuxRegs.GPDQUAL.bit.QUALPRD = 0;
  GpioMuxRegs.GPEQUAL.bit.QUALPRD = 0;
  EDIS;
}
