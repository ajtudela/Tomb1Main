#pragma once

#include "ddraw/ddraw.h"

#ifdef __cplusplus
extern "C" {
#endif

HRESULT MyDirectDrawCreate(LPDIRECTDRAW *lplpDD);

HRESULT MyIDirectDraw_Release(LPDIRECTDRAW p);

HRESULT MyIDirectDraw_SetDisplayMode(
    LPDIRECTDRAW p, DWORD dwWidth, DWORD dwHeight);

HRESULT MyIDirectDraw2_CreateSurface(
    LPDIRECTDRAW p, LPDDSURFACEDESC lpDDSurfaceDesc,
    LPDIRECTDRAWSURFACE *lplpDDSurface);

HRESULT MyIDirectDrawSurface_GetAttachedSurface(
    LPDIRECTDRAWSURFACE p, LPDDSCAPS lpDDSCaps,
    LPDIRECTDRAWSURFACE *lplpDDAttachedSurface);

HRESULT MyIDirectDrawSurface2_Lock(
    LPDIRECTDRAWSURFACE p, LPDDSURFACEDESC lpDDSurfaceDesc);

HRESULT MyIDirectDrawSurface2_Unlock(LPDIRECTDRAWSURFACE p, LPVOID lp);

HRESULT MyIDirectDrawSurface_Blt(
    LPDIRECTDRAWSURFACE p, LPRECT lpDestRect,
    LPDIRECTDRAWSURFACE lpDDSrcSurface, LPRECT lpSrcRect, DWORD dwFlags);

HRESULT MyIDirectDrawSurface_Release(LPDIRECTDRAWSURFACE p);

HRESULT MyIDirectDrawSurface_Flip(LPDIRECTDRAWSURFACE p);

#ifdef __cplusplus
}
#endif
