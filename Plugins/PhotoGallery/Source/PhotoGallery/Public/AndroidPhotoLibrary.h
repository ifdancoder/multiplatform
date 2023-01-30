// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PhotoInterface.h"

/**
 * 
 */
class PHOTOGALLERY_API AndroidPhotoLibrary : public IPhotoGallery
{
public:
	AndroidPhotoLibrary();

	virtual void OpenGallery() override;

#if PLATFORM_ANDROID
	static struct _JNIEnv* ENV;
#endif
};
