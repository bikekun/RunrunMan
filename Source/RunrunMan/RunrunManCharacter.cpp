// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "RunrunMan.h"
#include "RunrunManCharacter.h"

ARunrunManCharacter::ARunrunManCharacter()
{
	//Event tick
	PrimaryActorTick.bCanEverTick = true;
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate when the controller rotates.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Create a camera boom attached to the root (capsule)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->bAbsoluteRotation = true; // Rotation of the character should not affect rotation of boom
	CameraBoom->bDoCollisionTest = false;
	CameraBoom->TargetArmLength = 500.f;
	CameraBoom->SocketOffset = FVector(0.f,0.f,75.f);
	CameraBoom->RelativeRotation = FRotator(0.f,180.f,0.f);

	// Create a camera and attach to boom
	SideViewCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("SideViewCamera"));
	SideViewCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	SideViewCameraComponent->bUsePawnControlRotation = false; // We don't want the controller rotating the camera

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Face in the direction we are moving..
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->GravityScale = 2.f;
	GetCharacterMovement()->AirControl = 0.80f;
	GetCharacterMovement()->JumpZVelocity = 1000.f;
	GetCharacterMovement()->GroundFriction = 3.f;
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
	GetCharacterMovement()->MaxFlySpeed = 600.f;

	//инициализация параметров в компоненте ParametersComponent
	ParametersComponent = CreateDefaultSubobject <UParametersComponent>(TEXT("Param Component"));
	ParametersComponent->DDeath.AddUFunction(this, "Death");
	//ParametersComponent->DDeath.AddUFunction(this, "Death");
	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)

	//Вектор направления движения
	VRightVectorMoved			=  FVector(0.f, 0.f, 0.f);
	VRightVectorMovedDefault	= FVector(0.f, -1.f, 0.f);

	
}

//////////////////////////////////////////////////////////////////////////
// Input

void ARunrunManCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	{
		// set up gameplay key bindings
		/***********************************************************************/
		// отключить, в этом характере не должно быть
		InputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
		InputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
		//InputComponent->BindAxis("MoveRight", this, &ARunrunManCharacter::MoveRight);
		/***************************************************************************/
	}

	//Выставляет направление движения по умолчанию
	InputComponent->BindAction("StartRun", IE_Pressed, this, &ARunrunManCharacter::SetDefaultRightVector);
	//тестовая функция для разворота персонажа (отключить)
	InputComponent->BindAction("RevertRightVector", IE_Pressed, this, &ARunrunManCharacter::SetRevertRightVector);
	

	InputComponent->BindTouch(IE_Pressed, this, &ARunrunManCharacter::TouchStarted);
	InputComponent->BindTouch(IE_Released, this, &ARunrunManCharacter::TouchStopped);

	
	
}
// Движение вперед
void ARunrunManCharacter::MoveRight(float Value)
{
	// add movement in that direction
	AddMovementInput(VRightVectorMoved, Value);
}

void ARunrunManCharacter::TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location)
{	
	// jump on any touch
	Jump();
	
}

void ARunrunManCharacter::TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	StopJumping();
}

// Called every frame
void ARunrunManCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//GEngine->AddOnScreenDebugMessage(-1, 0, FColor::Red, FString::FromInt(BStartMoved));
	
		MoveRight(1);	//Заменить 1 на скорость движения с учетом тика
	
}



//void ARunrunManCharacter::BeginPlay()
//{
//	Super::BeginPlay();
//	
//	//SetDefaultRightVector();
//
//}

//Выставляет вектор в направление по умолчанию
void ARunrunManCharacter::SetDefaultRightVector()
{
	VRightVectorMoved = VRightVectorMovedDefault;	
}
//тестовая функция для разворота персонажа (отключить)
void ARunrunManCharacter::SetRevertRightVector()
{
	VRightVectorMoved = -1 * VRightVectorMoved;
}

void ARunrunManCharacter::Death()
{
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Blue, TEXT("Death"), true);
}

void ARunrunManCharacter::PostInitProperties()
{
	Super::PostInitProperties();
	ParametersComponent->SetMaxHealth(ParametersComponent->DefaultMaxHealth);
	ParametersComponent->HealthToMax();
}