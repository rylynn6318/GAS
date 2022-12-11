#include "GASPlayerController.h"
#include "Ability/GASAbilitySystemComponent.h"
#include "GASCharacter.h"

void AGASPlayerController::PostProcessInput(const float DeltaTime, const bool bGamePaused)
{
	APawn* OwnerCharacter = GetPawn();
	if (OwnerCharacter)
	{
		if (UGASAbilitySystemComponent* ASC = Cast<AGASCharacter>(OwnerCharacter)->GetGASAbilitySystemComponent())
		{
			ASC->ProcessAbilityInput(DeltaTime, bGamePaused);
		}
	}

	Super::PostProcessInput(DeltaTime, bGamePaused);
}
