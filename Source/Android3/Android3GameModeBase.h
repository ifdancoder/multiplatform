// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Android3GameModeBase.generated.h"

#if PLATFORM_ANDROID || PLATFORM_IOS
#include "src/pugixml.hpp"
#endif

/**
 * 
 */
UCLASS()
class ANDROID3_API AAndroid3GameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	class IPhotoGallery* PhotoLibrary;

protected:
	virtual void BeginPlay() override;

	void OpenGallery();

	void OnImageSelected(TArray<uint8> PhotoBytes);

#if PLATFORM_ANDROID || PLATFORM_IOS
	pugi::xml_document GetDocument();
#endif
};
