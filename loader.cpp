#include "loader.h"

void Loader::RestoreState(vector<Figure*> figures)
{
	ApplicationFacade::GetInstance(nullptr)
		->RestoreState(figures);
}

vector<Figure*> Loader::ReadFiguresFromString(string str)
{
	auto data = vector<Figure*>();

	istringstream stream(str);
	string line;
	string grouped = "";
	int groupCount = 0;

	while (getline(stream, line))
	{
		if (line == "GroupedStarted")
		{
			if (groupCount == 0)
				grouped.append("Grouped\n");
			else grouped.append("GroupedStarted\n");

			groupCount++;
			continue;
		}

		else if (line == "GroupedEnded")
		{
			if (groupCount == 1)
			{
				data.push_back(ReadGroupedFromString(grouped));
				grouped = "";
				groupCount = 0;
				continue;
			}
			groupCount--;
		}

		if (grouped == "")
			data.push_back(ReadFigureFromString(line));
		else grouped.append(line + '\n');
	}

	return data;
}

GroupedFigure* Loader::ReadGroupedFromString(string str)
{
	auto grouped = GroupedFigureBuilder();

	istringstream stream(str);
	string line;

	getline(stream, line);

	string temp = "";
	while (getline(stream, line))
	{
		if (line == "GroupedStarted")
		{
			temp.append("Grouped\n");
			continue;
		}

		else if (line == "GroupedEnded")
		{
			grouped.AddFigure(ReadGroupedFromString(temp));
			temp = "";
			continue;
		}

		if (temp == "")
			grouped.AddFigure(ReadFigureFromString(line));
		else temp.append(line + '\n');
	}
	return (GroupedFigure*)grouped.Build()->GetFigure();
}

Figure* Loader::ReadFigureFromString(string str)
{
	auto temp = MyExtensions::Split(str, ' ');

	if (temp[0] == "Rectangle")
		return RectangleBuilder()
		.SetSize(Vector2f(stoi(temp[3]), stoi(temp[4])))
		->SetPosition(Vector2f(stoi(temp[1]), stoi(temp[2])))
		->SetFillColor(Color(stoul(temp[5])))
		->SetOutlineColor(Color(stoul(temp[6])))
		->SetOutlineThickness(stoi(temp[7]))
		->Build()
		->GetFigure();



	else if (temp[0] == "Triangle")
		return TriangleBuilder()
		.SetPointCount(3)
		->SetPoint(0, Vector2f(stoi(temp[1]), stoi(temp[2])))
		->SetPoint(1, Vector2f(stoi(temp[3]), stoi(temp[4])))
		->SetPoint(2, Vector2f(stoi(temp[5]), stoi(temp[6])))
		->SetPosition(Vector2f(stoi(temp[7]), stoi(temp[8])))
		->SetFillColor(Color(stoul(temp[9])))
		->SetOutlineColor(Color(stoul(temp[10])))
		->SetOutlineThickness(stoi(temp[11]))
		->Build()
		->GetFigure();

	else if (temp[0] == "Circle")
		return CircleBuilder()
			.SetRadius(stoi(temp[3]))
			->SetPosition(Vector2f(stoi(temp[1]), stoi(temp[2])))
			->SetFillColor(Color(stoul(temp[4])))
			->SetOutlineColor(Color(stoul(temp[5])))
			->SetOutlineThickness(stoi(temp[6]))
			->Build()
			->GetFigure();

	return nullptr;
}

void Loader::Load(string filename)
{
	RestoreState(ReadFile(filename));
}
