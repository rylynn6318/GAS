// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "GASCharacter.generated.h"

struct FInputActionValue;
struct FGameplayTag;

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

	virtual void Input_AbilityInputTagPressed(FGameplayTag InputTag);
	virtual void Input_AbilityInputTagReleased(FGameplayTag InputTag);
	virtual void Input_Move(const FInputActionValue& InputActionValue);
	virtual void Input_Look(const FInputActionValue& InputActionValue);
	virtual void Input_Sprint(const FInputActionValue& InputActionValue);
	virtual void Input_Dodge(const FInputActionValue& InputActionValue);
	virtual void Input_Jump(const FInputActionValue& InputActionValue);

	UFUNCTION(BlueprintCallable)
	virtual float GetHealth() const;

	UFUNCTION(BlueprintCallable)
	virtual float GetMaxHealth() const;

	UFUNCTION(BlueprintCallable)
	virtual float GetMana() const;

	UFUNCTION(BlueprintCallable)
	virtual float GetMaxMana() const;

protected:
	void MoveForward(float Value);
	void MoveRight(float Value);
	void TurnAtRate(float Rate);
	void LookUpAtRate(float Rate);

protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Input)
	float TurnRateGamepad;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class USpringArmComponent> CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UCameraComponent> FollowCamera;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<class UGASInputConfig> InputConfig;

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<class UGASAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ability")
	TArray<TObjectPtr<class UGASAbilitySet>> AbilitySets;

	UPROPERTY()
	TObjectPtr<class UBaseStatAttributeSet> StatAttributeSet;
};

