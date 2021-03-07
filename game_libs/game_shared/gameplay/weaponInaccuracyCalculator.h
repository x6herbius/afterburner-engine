#pragma once

namespace WeaponAtts
{
	struct AccuracyParameters;
}

typedef struct weapon_data_s weapon_data_t;
typedef struct cvar_s cvar_t;

class CBasePlayer;

class CWeaponInaccuracyCalculator
{
public:
	using Accuracy = WeaponAtts::AccuracyParameters;

	CWeaponInaccuracyCalculator();

	bool IsValid() const;
	void Clear();
	void CalculateInaccuracy();
	void AddInaccuracyPenaltyFromFiring();

	void ReadFromPredictionData(const weapon_data_t& from);
	void WriteToPredictionData(weapon_data_t& to);

	float InstantaneousInaccuracy() const;
	float SmoothedInaccuracy() const;

	const Accuracy* AccuracyParams() const;
	void SetAccuracyParams(const Accuracy* params);

	CBasePlayer* Player() const;
	void SetPlayer(CBasePlayer* player);

	void SetFiredThisFrame(bool fired);

private:
	void CalculateInstantaneousInaccuracy();
	void CalculateSmoothedInaccuracy();

	// These variables don't have defaults set here, because they
	// are set to their defaults in Clear() instead.
	float m_InstantaneousInaccuracy;
	float m_SmoothedInaccuracy;
	float m_LastSmoothedInaccuracy;
	bool m_FiredThisFrame;
	const WeaponAtts::AccuracyParameters* m_AccuracyParams;
	CBasePlayer* m_Player;

	cvar_t* m_CvarMaxSpeed = nullptr;
	cvar_t* m_CvarMaxFallSpeed = nullptr;
};
