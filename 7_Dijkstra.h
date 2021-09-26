#pragma once
#include "base.h"

struct GraphNode {
	std::vector<std::pair<GraphNode*, std::size_t>> children;
	std::size_t weight;
	std::size_t id;

	GraphNode(std::size_t _id, std::size_t _weight) : weight(_weight), id(_id) {};

	bool operator<(const GraphNode gn) {
		return this->weight < gn.weight;
	}

	friend bool operator<(const GraphNode gn1, const GraphNode gn2) {
		return gn1.weight < gn2.weight;
	}
};

/*Retunr vector of ids in optimal path*/
std::vector<std::size_t> findOptimalPath(GraphNode* first_node, GraphNode* end_node) {
	std::set<GraphNode> tempNodes;

	tempNodes.insert(*first_node);

	std::unordered_map<std::size_t, std::size_t> edges;

	while (!tempNodes.empty()) {
		auto currentNode = *tempNodes.begin();
		tempNodes.erase(tempNodes.begin());
		if (currentNode.id == end_node->id) {
			break;
		}

		for (auto& child : currentNode.children) {
			if (child.first->weight > currentNode.weight + child.second) {
				child.first->weight = currentNode.weight + child.second;
				edges.insert_or_assign(child.first->id, currentNode.id);
			}
			tempNodes.insert(*child.first);
		}
	}

	std::vector<std::size_t> result(edges.size() + 1);

	auto currentNode = edges.find(end_node->id);

	int i = edges.size();
	while (currentNode != edges.end()) {
		result[i] = (*currentNode).first;
		--i;
		currentNode = edges.find((*currentNode).second);
	}
	result[0] = first_node->id;
	return result;
}