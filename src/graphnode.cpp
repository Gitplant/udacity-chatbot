#include <memory>

#include "graphedge.h"
#include "graphnode.h"

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////

    // delete _chatBot;

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(GraphEdge *edge)
{
    _childEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode2(std::unique_ptr<GraphEdge> edge)
{
    _childEdges.push_back(edge.get());
}
//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot *chatbot)
{
    _chatBot = chatbot;
    _chatBot->SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    //Temp for testing copying and moving (Task 2):
    ChatBot _chatBot2(*_chatBot);  // Copy constructor
    ChatBot _chatBot3;
    _chatBot3 = *_chatBot;  // Copy assignment operator
    ChatBot _chatBot5 = ChatBot(std::move(_chatBot2)); // Move constructor
    ChatBot _chatBot6;
    _chatBot6 = std::move(_chatBot5); // Move assignment operator
    //End

    newNode->MoveChatbotHere(_chatBot);
    _chatBot = nullptr; // invalidate pointer at source
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    return _childEdges[index];

    ////
    //// EOF STUDENT CODE
}