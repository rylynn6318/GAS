// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "GASCharacter.generated.h"

struct FInputActionValue;
struct FGameplayTag;
struct FOnAttributeChangeData;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHPChanged, float, CurrentHP, float, MaxHP);

UCLASS(BlueprintType, Blueprintable)
class AGASCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AGASCharacter();
	virtual void BeginPlay() override;
	virtual void PossessedBy(AController* NewController) override;

	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom.Get(); }
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera.Get(); }

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	virtual class UGASAbilitySystemComponent* GetGASAbilitySystemComponent() const;

	UFUNCTION(BlueprintCallable)
	virtual float GetHealth() const;

	UFUNCTION(BlueprintCallable)
	virtual float GetMaxHealth() const;

	UFUNCTION(BlueprintCallable)
	virtual float GetMana() const;

	UFUNCTION(BlueprintCallable)
	virtual float GetMaxMana() const;

	UFUNCTION(BlueprintCallable)
	virtual int32 GetCharacterLevel() const {return CharacterLevel;}

protected:
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	
protected:
	void MoveForward(float Value);
	void MoveRight(float Value);
	void TurnAtRate(float Rate);
	void LookUpAtRate(float Rate);

	void OnHealthChanged(const FOnAttributeChangeData& ChangeData);
	void OnMaxHealthChanged(const FOnAttributeChangeData& ChangeData);
	
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Input)
	float TurnRateGamepad;

	UPROPERTY(BlueprintAssignable)
	FOnHPChanged OnHPChanged;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class USpringArmComponent> CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UCameraComponent> FollowCamera;

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<class UGASAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<class UBaseStatAttributeSet> StatAttributeSet;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int32 CharacterLevel;

	UPROPERTY(EditDefaultsOnly, Category = "GASCharacter")
	TArray<TSubclassOf<class UGameplayAbility>> PassiveGameplayAbilities;

	UPROPERTY(EditDefaultsOnly, Category = "GASCharacter")
	TArray<TSubclassOf<class UGameplayEffect>> PassiveGameplayEffects;
};
