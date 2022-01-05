// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class UNREALGAME_API UCAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
protected:
	//BulueprintReadonly : ���ũ��Ʈ �б� ����
	//���Ͱ� �ƴ� Ŭ�������� �������� ������ �����Ҷ�
	//�̷��� �ؾ� �����Ϳ� ��Ÿ��

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Animation")
		float Speed;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Animation")
		float Direction;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Animation")
		float Pitch;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Animation")
		bool bEquipped;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Animation")
		bool bAiming;


public:
	virtual void NativeBeginPlay() override;
	//override: �θ𿡼� �����ǵ� �Լ���� ������ִ� Ű����
	//�⺻ c++������ �����ص� ������ �𸮾� C++������ �ʼ�
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

private:
	class ACharacter* OwnerCharacter;
};
