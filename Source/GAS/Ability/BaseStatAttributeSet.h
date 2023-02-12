#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "BaseStatAttributeSet.generated.h"

// Uses macros from AttributeSet.h
// The following example of the macro :
// ATTRIBUTE_ACCESSORS(UBaseStatAttributeSet, Health)
// will create the following functions :
// static FGameplayAttribute GetHealthAttribute();
// float GetHealth() const;
// void SetHealth(float NewVal);
// void InitHealth(float NewVal);

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName) 

UCLASS()
class GAS_API UBaseStatAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

protected:
	void AdjustAttributeForMaxChange(FGameplayAttributeData& AffectedAttribute, const FGameplayAttributeData& MaxAttribute, float NewMaxValue, const FGameplayAttribute& AffectedAttributeProperty);

public:
	ATTRIBUTE_ACCESSORS(UBaseStatAttributeSet, Health)
	ATTRIBUTE_ACCESSORS(UBaseStatAttributeSet, MaxHealth)
	ATTRIBUTE_ACCESSORS(UBaseStatAttributeSet, Stamina)
	ATTRIBUTE_ACCESSORS(UBaseStatAttributeSet, MaxStamina)
	ATTRIBUTE_ACCESSORS(UBaseStatAttributeSet, AttackPower)
	ATTRIBUTE_ACCESSORS(UBaseStatAttributeSet, DefensePower)
	ATTRIBUTE_ACCESSORS(UBaseStatAttributeSet, MoveSpeed)
	ATTRIBUTE_ACCESSORS(UBaseStatAttributeSet, Damage)

protected:
	UPROPERTY(BlueprintReadOnly, Category = "BaseStat")
	FGameplayAttributeData Health;

	UPROPERTY(BlueprintReadOnly, Category = "BaseStat")
	FGameplayAttributeData MaxHealth;

	UPROPERTY(BlueprintReadOnly, Category = "BaseStat")
	FGameplayAttributeData Stamina;

	UPROPERTY(BlueprintReadOnly, Category = "BaseStat")
	FGameplayAttributeData MaxStamina;

	UPROPERTY(BlueprintReadOnly, Category = "BaseStat")
	FGameplayAttributeData MoveSpeed;

	UPROPERTY(BlueprintReadOnly, Category = "BaseStat")
	FGameplayAttributeData AttackPower;

	UPROPERTY(BlueprintReadOnly, Category = "BaseStat")
	FGameplayAttributeData DefensePower;

	// 임시로 받아야할 데미지를 저장하는 변수
	UPROPERTY(BlueprintReadOnly, Category = "BaseStat")
	FGameplayAttributeData Damage;
};
