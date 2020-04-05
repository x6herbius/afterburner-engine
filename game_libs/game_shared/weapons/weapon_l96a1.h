#pragma once

#include "standard_includes.h"
#include "generichitscanweapon.h"

class CWeaponL96A1 : public CGenericHitscanWeapon
{
public:
	CWeaponL96A1();

	virtual const WeaponAtts::WACollection& WeaponAttributes() const override;

	virtual void SecondaryAttack() override;
	virtual BOOL Deploy() override;
	virtual void Holster(int skiplocal = 0) override;

#ifndef CLIENT_DLL
	virtual float Bot_CalcDesireToUse(CBaseBot& bot, CBaseEntity& enemy, float distanceToEnemy) const override;
	virtual void Bot_SetFightStyle(CBaseBotFightStyle& fightStyle) const override;
#endif

private:
	void SetZoomLevel(uint32_t level);

	uint32_t m_iZoomLevel = 0;
	int m_iViewModel = 0;
};

namespace WeaponAtts
{
	template<>
	const WACollection& StaticWeaponAttributes<CWeaponL96A1>();
}
