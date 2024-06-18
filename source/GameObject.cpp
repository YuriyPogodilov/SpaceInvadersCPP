#include "GameObject.h"
#include <cassert>
#include <iostream>
#include <SDL.h>
#include "RendererHelper.h"

std::shared_ptr<GameObject> GameObject::getPtr() {
	return shared_from_this();
}

GameObject::GameObject(std::string_view name) :
		name(name)
{
	assert(!name.empty());
}

std::weak_ptr<GameObject> GameObject::GetParent() const {
	return parent;
}

void GameObject::AddChild(std::shared_ptr<GameObject> newChild) {
	newChild->parent = weak_from_this();
	children.push_back(newChild);
}

void GameObject::Update(float deltaTime) {
	for (auto& child : children) {
		child->Update(deltaTime);
	}
}

void GameObject::Draw(SDL_Renderer *renderer) {
	for (auto& child : children) {
		child->Draw(renderer);
	}

	if (bShowOutline) {
		DrawOutline(renderer);
	}
}

void GameObject::DrawOutline(SDL_Renderer *renderer) {
	Point leftTop = { position.x - size.x * pivot.x, position.y - size.y * pivot.y };
	Point rightBottom = { position.x + size.x * pivot.x, position.y + size.y * pivot.y };
	RendererHelper::DrawRect(renderer, leftTop, rightBottom);
}

void GameObject::PrintHierarchy(int level /* = 0 */) const {
	for (int i = 0; i < level; ++i) std::cout << "  ";
	std::cout << name << std::endl;
	for (const auto& child : children) {
		child->PrintHierarchy(level + 1);
	}
}

void GameObject::SetPosition(Point newPosition) {
	position = newPosition;
}

Point GameObject::GetPosition() const {
	return position;
}
