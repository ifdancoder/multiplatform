// Copyright Epic Games, Inc. All Rights Reserved.


#include "Android3GameModeBase.h"
#include "AndroidPhotoLibrary.h"
#include "IOSPhotoLibrary.h"

void AAndroid3GameModeBase::BeginPlay()
{
	Super::BeginPlay();

#if PLATFORM_ANDROID
	PhotoLibrary = new AndroidPhotoLibrary();
#endif

#if PLATFORM_IOS
	PhotoLibrary = new IOSPhotoLibrary();
#endif
}

void AAndroid3GameModeBase::OpenGallery()
{
	if (PhotoLibrary)
	{
#if PLATFORM_ANDROID
		PhotoLibrary->OnImageSelected.BindUObject(this, &AAndroid3GameModeBase::OnImageSelected);
#endif
#if PLATFORM_IOS
		PhotoLibrary->OnImageSelected.BindUObject(this, &AAndroid3GameModeBase::OnImageSelected);
#endif
	}
}

void AAndroid3GameModeBase::OnImageSelected(TArray<uint8> PhotoBytes)
{
	int32 len = PhotoBytes.Num();

	AsyncTask(ENamedThreads::GameThread, [=]()
	{
		
	}
	);
}

#if PLATFORM_ANDROID || PLATFORM_IOS
pugi::xml_document AAndroid3GameModeBase::GetDocument()
{
	pugi::xml_document doc;

	pugi::xml_parse_result = doc.load_file("tree.xml");

	return doc;
}
#endif
