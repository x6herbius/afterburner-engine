#pragma once

#include "ui/core/uiVec2.h"

class CCrosshairParameters
{
public:
	CCrosshairParameters();
	void Reset();

	const UIVec2& ScreenDimensions() const;
	void SetScreenDimensions(const UIVec2& dim);

	float WeaponInaccuracy() const;
	void SetWeaponInaccuracy(float inaccuracy);

	UIVec2 HalfScreenDimensions() const;
	int DisplacementFromScreenCentre(float fraction) const;
private:
	UIVec2 m_ScreenDimensions;
	float m_WeaponInaccuracy = 0.0f;
};
