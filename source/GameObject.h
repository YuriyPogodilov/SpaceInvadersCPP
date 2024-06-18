#pragma once

#include <vector>
#include <string>
#include <string_view>
#include <memory>

class SDL_Renderer;

class GameObject : public std::enable_shared_from_this<GameObject> {
public:
	std::shared_ptr<GameObject> getPtr();

	explicit GameObject(std::string_view data);
	virtual ~GameObject() = default;

	virtual void Update(float deltaTime);
	virtual void Draw(SDL_Renderer* renderer);

	std::weak_ptr<GameObject> GetParent() const;
	void AddChild(std::shared_ptr<GameObject> newChild);

	void PrintHierarchy(int level = 0) const;

protected:
	std::string name;
	std::weak_ptr<GameObject> parent;
	std::vector<std::shared_ptr<GameObject>> children;
};
