#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct Node { int id; double x, y, z; };
struct Element { int id; int type; std::vector<int> nodeIds; };

void generateAPDLFile(
	const std::string& filename,
	const std::vector<Node>& nodes,
	const std::vector<Element>& elements
) {
	std::ofstream file(filename);
	if (!file.is_open()) {
		std::cerr << "无法创建文件：" << filename << std::endl;
		return;
	}
	//写入APDL命令头
	file << "/PREP7\n";
	file << "ET,1,BEAM188\n";
	file << "MP,EX,1,2.1E5\n";
	file << "MP,PRXY,1,0.3\n";
	file << "SECTYPE,1,BEAM,RECT\n";
	file << "SECDATA,50,100\n";

	for (const auto& node : nodes) {
		file << "N," << node.id << "," << node.x << "," << node.y << "," << node.z << "\n";
	}

	for (const auto& elem : elements) {
		file << "E";
		for (int nodeId : elem.nodeIds) {
			file << "," << nodeId;
		}
		file << "\n";
	}
	file << "FINISH\n";
	file.close();
	std::cout << "APDL文件已生成：" << filename << std::endl;
}

int main() {
	const double length = 1000.0;
	const int numElements = 10;
	const int numNodes = numElements + 1;

	std::vector<Node> nodes;
	for (int i = 0; i < numNodes; ++i) {
		double x = i * (length / numElements);
		nodes.push_back({ i + 1, x, 0.0, 0.0 });
	}

	std::vector<Element> elements;
	for (int i = 0; i < numElements; ++i) {
		elements.push_back({ i + 1, 1, {i + 1, i + 2} });
	}

	generateAPDLFile("beam_model.mac", nodes, elements);
	return 0;
}