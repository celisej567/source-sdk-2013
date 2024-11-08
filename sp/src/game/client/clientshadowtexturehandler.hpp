#pragma once

#include "cbase.h"
#include "materialsystem/itexture.h"

class CFlashlightDepthHandler
{
public:
	CFlashlightDepthHandler()
	{
		
	}

	~CFlashlightDepthHandler()
	{
		m_ShadowDepthTexture.Purge();
	}

	void AddDepthTexture(ShadowHandle_t index, CTextureReference tex)
	{
		m_ShadowDepthTexture.InsertOrReplace(index, tex);
	}

	int GetCount() { return m_ShadowDepthTexture.Count(); }

	CTextureReference GetDepthTexture(ShadowHandle_t index) 
	{
		int i = m_ShadowDepthTexture.Find(index);

		return m_ShadowDepthTexture[i];
	}

private:

	CUtlMap<ShadowHandle_t, CTextureReference, int> m_ShadowDepthTexture;




};

CFlashlightDepthHandler g_flashlightDepthHandler;