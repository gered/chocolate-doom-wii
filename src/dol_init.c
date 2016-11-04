#ifdef GEKKO

#include "dol_init.h"

#include <stdio.h>

#include <gccore.h>
#include <fat.h>
#include <debug.h>

static void *xfb = NULL;
static GXRModeObj *rmode = NULL;

void DOL_Init()
{
#ifdef DEBUG_USBGECKO
	DEBUG_Init(GDBSTUB_DEVICE_USB, 1);
	_break();
#endif

	VIDEO_Init();
	rmode = VIDEO_GetPreferredMode(NULL);
	xfb = MEM_K0_TO_K1(SYS_AllocateFramebuffer(rmode));

	console_init(xfb, 20, 20, rmode->fbWidth, rmode->xfbHeight, rmode->fbWidth * VI_DISPLAY_PIX_SZ);
	
	VIDEO_Configure(rmode);
	VIDEO_SetNextFramebuffer(xfb);
	VIDEO_SetBlack(FALSE);
	VIDEO_Flush();
	VIDEO_WaitVSync();
	if(rmode->viTVMode & VI_NON_INTERLACE)
	{
		VIDEO_WaitVSync();
	}

	// helps ensure TV overscan won't cut off initial console output
	printf("\x1b[2;0H");

	printf("DOL_Init: Console video init finished.\n");

	if (!fatInitDefault())
	{
		printf("DOL_Init: *** FATAL: fatInitDefault failed.\n");
		exit(1);
	}
	else
	{
		printf("DOL_Init: fatInitDefault success.\n");
	}
}

#endif

