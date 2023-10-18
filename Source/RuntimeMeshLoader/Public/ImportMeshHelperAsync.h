// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "DataType.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ImportMeshHelperAsync.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FImportMeshCompleteDelegate, const FReturnedData&, Result);

/**
 * 
 */
UCLASS()
class RUNTIMEMESHLOADER_API UImportMeshHelperAsync : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "MeshLoader", meta = (BlueprintInternalUseOnly = "true"))
	static UImportMeshHelperAsync* LoadMeshAsync(const FString& FilePath, EPathType Type = EPathType::Absolute);

	UPROPERTY(BlueprintAssignable)
	FImportMeshCompleteDelegate OnComplete;
private:
	FReturnedData LoadMesh(FString filepath,EPathType type= EPathType:: Absolute);
};
