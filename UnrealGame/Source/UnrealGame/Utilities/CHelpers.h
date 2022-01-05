#pragma once
#include "CoreMinimal.h"
#include "UObject/ConstructorHelpers.h"

//언리얼 네임스페이스
//어느 프로젝트에 소속된 소스인지 구분
class UNREALGAME_API CHelpers
{
public:
	template<typename T>//자료형 이름을 바꿔줌
	static void GetAsset(T** OutObject, FString InPath)
	{
		ConstructorHelpers::FObjectFinder<T> asset(*InPath);
		//오류가났을때 개발중에 오류값을 체크가능
		//에디터상에서 사용
		//실제 서비스할때는 실행하지않음
		verifyf(asset.Succeeded(), L"asset.Succeeded()");

		*OutObject = asset.Object;
	}

	template<typename T>
	static void GetAssetDynamic(T** OutObject, FString InPath)
	{
		T* obj = Cast<T>(StaticLoadObject(T::StaticClass(), NULL, *InPath));
		//!!언리얼에서는 obj !=NULL 같은 표현이 된다.
		verifyf(!!obj, L"!!obj");

		*OutObject = obj;
	}

	template<typename T>//기본적으로 Tsub클래스가 포인터이다.
	static void GetClass(TSubclassOf<T>* OutClass, FString InPath)
	{
		ConstructorHelpers::FClassFinder<T> asset(*InPath);
		verifyf(asset.Succeeded(), L"asset.Succeeded()");

		*OutClass = asset.Class;
	}

	template<typename T>
	static void CreateComponent(AActor* InActor, T** InComponent, FName InName, USceneComponent* Inparent = NULL)
	{
		*InComponent = InActor->CreateDefaultSubobject<T>(InName);

		if (!!Inparent)
		{
			(*InComponent)->SetupAttachment(Inparent);

			return;
		}

		InActor->SetRootComponent((*InComponent));
	}

		template<typename T>
	static void CreateActorComponent(AActor* InActor, T** InComponent, FName InName)
	{
		*InComponent = InActor->CreateDefaultSubobject<T>(InName);				
	}

	template<typename T>
	static void FindActors(class UWorld* InWorld, TArray<T*>& OutActors)
	{
		TArray<AActor*> actors;
		UGameplayStatics::GetAllActorsOfClass(InWorld, T::StaticClass(), actors);

		for (AActor* actor : actors)
			OutActors.Add(Cast<T>(actor));
	}

};