// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"



DECLARE_LOG_CATEGORY_EXTERN(KHG_LOG, Log, All);

#define KLOG_CALLINFO (FString(__FUNCTION__)+TEXT("(")+FString::FromInt(__LINE__)+TEXT(")"))
#define KLOG_S(Verbosity)  UE_LOG(KHG_LOG,Verbosity,*KLOG_CALLINFO)
#define KLOG(Verbosity,Coment, ...) UE_LOG(KHG_LOG,Verbosity,TEXT("%s_%s"),*KLOG_CALLINFO,*FString(Coment,##__VA_ARGS__))
#define KLOG_W(Coment) KLOG(Warning,Coment)
#define KLOG_E(Coment) KLOG(Error,Coment)
//ELogVerbosity
/**
 * 
 */
class LO_API KHG_STD
{
public:
	KHG_STD();
	~KHG_STD();
};
